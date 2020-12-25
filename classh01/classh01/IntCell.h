#ifndef INTCELL_H
#define INTCELL_H
class IntCell
{
	public:
		explicit IntCell(int initialValue = 0);
		int read() const;
		void write(int X);
	private:
		int storedValue;
};
#endif