 #include<iostream> 
#include<time.h> 
#include<String> 
using namespace std; 
#include<GL\glut.h> 

void draw(int xc, int yc, int size); 
void init(void); 
void Display (void); 
void move(int value); 
void menu(); 
void win() ; 
void keyboard (GLubyte key, int x, int y); 
void special(int key, int x, int y); 
void mouse(int button, int action, int x, int y); 
void drawScore(); 
void initRandom(); 

int xSpeed[15],ySpeed[15];
int Menu = 2, score=0; 
int xC[15],yC[15],size[15]; 
float color[3][15]; 

void main(int argc, char** argv){
    glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowPosition(50,50); 
    glutInitWindowSize(800,600); 
    glutCreateWindow("Assignment_1"); 
    init(); 
    glutDisplayFunc(Display); 
    glutTimerFunc(10 , move , 0); 
    glutKeyboardFunc(keyboard); 
    glutSpecialFunc(special); 
    glutMouseFunc(mouse); 
    glutMainLoop();
}

void init() {
    glClearColor(1.0, 1.0, 1.0,0.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(0.0,800.0,0.0,600.0); 
    initRandom();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    if (Menu == 1){ 
        for(int i=0;i<15;i++) { 
            glColor3f(color[0][i], color[1][i],color[2][i]);
            draw(xC[i],yC[i], size[i]);
        }
        drawScore();
        if (score == 15) win(); 
        else drawScore();
    }
    else if(Menu == 2) menu();
    glFlush();
}

void draw(int xc, int yc, int size) {
    int x, y, angle = 0; 
    glBegin(GL_POLYGON); 
    for(int i=0; i<4;i++) {
        x = x + (int)(size * cos(3.14/180 * angle)); 
        y = y + (int)(size * sin(3.14/180 * angle)); 
		//x = (int)10.5;
		//y = (int)5.5;
        glVertex2i(x,y); 
        angle += 90;
    }
    glEnd();
}

void move(int value) { 
    for(int i=0;i<15; i++) {
        xC[i] += xSpeed[i]; 
        yC[i] += ySpeed[i]; 
        if(xC[i]+size[i] >= 800) xSpeed[i] = -xSpeed[i]; 
        if(xC[i]-size[i] <= 0) xSpeed[i] = -xSpeed[i]; 
        if(yC[i]+size[i] >= 600) ySpeed[i] = -ySpeed[i]; 
        if(yC[i]-size[i] <= 0) ySpeed[i] = -ySpeed[i];
    }
    glutTimerFunc(10 , move , 0); 
    glutPostRedisplay();
}

void menu() {
    GLubyte text[31] = {'W', 'e', 'l', 'c','o', 'm', 'e',' ','t','o',' ','G', 'a','m', 'e',' ',
    'B', 'y',' ','C','+','+',' ','&',' ','0', 'p', 'e','n', 'G', 'L'}; 
    GLubyte text_1[14] = {'F','1','-',' ','P', 'l', 'a', 'y',' ', 'G', 'a','m', 'e' }; 
    GLubyte text_2[14] = {'F', '2',' ','S','t','o', 'p',' ', 'G', 'a', 'm', 'e'}; 
    GLubyte text_3[15] = {'E', 'S', 'C',' ',' ',' ', 'Q', 'u', 'i','t',' ', 'G', 'a', 'm', 'e' };
    glRasterPos2i(271,401); 
    glColor3f(1.0, 0.0,1.0); 

    for(int i =0; i<31; i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    glRasterPos2i(270,400); 
    glColor3f(0.0,0.0,0.0); 
    for(int i =0; i<31; i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    glColor3f(1.0,0.0,1.0);
    glRasterPos2i(300,379); 
    for(int i = 0; i<14;i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text_1[i]); 
    glRasterPos2i(300,350); 
    for(int i =0; i<14;i++) 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text_2[i]);
    glRasterPos2i(300, 330); 
        for(int i =0; i<15; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text_3[i]);
}

void keyboard(GLubyte key, int x, int y){
    if (key == 27) exit(0); 
    if (key == 13 && score) {
        score = 0; 
        initRandom(); 
        Menu =2;
    }
}

void special(int key, int x, int y){
    if(key == 1) Menu = 1;
    else if(key == 2) Menu = 2;
}

void mouse(int button, int action, int x, int y){ 
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
        y = 600-y; 
        for(int i=0;i<15; i++){
            if((x >= xC[i]-size[i])&&(x <= xC[i]+size[i])&&(y <= yC[i]+size[i])&&(y >= yC[i]-size[i])){
                xC[i] = 1200; 
                yC[i] = 1000; 
                xSpeed[i] = 0; 
                ySpeed[i] = 0; 
                score++; 
                break;
            }
        }
    }
}

void initRandom() {
    srand(time(NULL)); 
    for(int i=0;i<15;i++){
        xC[i] = rand() % 700 + 50; 
        yC[i] = rand() % 500 + 50; 
        size[i] = rand() % 40 + 20; 
        do {
            xSpeed[i] = rand() % 7 - 3; 
            ySpeed[i] = rand() % 7 - 3; 
        }while(xSpeed[i] == 0 || ySpeed[i] == 0); 
        do{
            do{ 
                color[0][i] = rand()%2; 
                color[1][i] = rand()%2; 
                color[2][i] = rand()%2;
            } while(color[0][i]==1 && color[1][i] == 1 && color[2][i] ==1); 
        } while(color[0][i]==0 && color[1][i] == 0 && color[2][i] ==0);
    }
}

void drawScore(){ 
    GLubyte text[8] = {'S','c','o', 'r', 'e',' ','0',' '}; 
    if(score == 1)text[6] = '1'; 
    if(score == 2)text[6] = '2'; 
    if(score == 3)text[6] = '3'; 
    if(score == 4)text[6] = '4'; 
    if(score == 5)text[6] = '5'; 
    if(score == 6)text[6] = '6'; 
    if(score == 7)text[6] = '7'; 
    if(score == 8)text[6] = '8'; 
    if(score == 9)text[6] = '9'; 
    if(score == 10){
        text[6] = '1'; 
        text[7] = '0';
    }
    if(score == 11){
        text[6] = '1'; 
        text[7] = '1';
    }
    if(score == 12){
        text[6] = '1'; 
        text[7] = '2';
    }
    if(score == 13){
        text[6] = '1'; 
        text[7] = '3';
    }
    if(score == 14){
        text[6] = '1'; 
        text[7] = '4';
    }
    if(score == 15){
        text[6] = '1'; 
        text[7] = '5';
    }
    glRasterPos2i(20,530); 
    glColor3f(0.0,0.0,0.0); 
    for(int i =0; i<8;i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void win() {
    glClear(GL_COLOR_BUFFER_BIT);
    GLubyte text_3[41] = {'<','<','<',' ','Y','o', 'u',' ','W','i', 'n', '!',' ','P','r', 'e', 's', 's',' ',
    'E','n','t', 'e', 'r',' ','t','o',' ','M', 'a', 'i','n',' ','M', 'e','n', 'u',' ','>','>','>'};
    glColor3f(0.0,0.0,0.); 
    glRasterPos2i( 220, 300); 
    for( int n = 0; n < 41 ; n++)
        glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, text_3[n]); 
    glColor3f(1.0,0.0,0.0); 
    glRasterPos2i( 219, 299); 
    for(int n = 0; n < 41 ; n++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text_3[n]); 
    glFlush();
}






