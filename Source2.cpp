#include <iostream>

template <typename T>
class Stack
{
	T* stackPtr;
	int size;
	int counter = -1;
public:
	Stack(int size_) : size(size_)
	{
		stackPtr = new T[size];
	}
	T pop()
	{
		if (counter != -1)
		{
			T element = stackPtr[counter];
			stackPtr[counter] = 0;
			counter--;
			return(element);
		}
		else
		{
			std::cout << "Stack is empty!" << std::endl;
		}
	};

	void push(const T element)
	{
		if (counter + 1 == size)
		{
			std::cout << "Stack is full!" << std::endl;
		}
		else
		{
			counter++;
			stackPtr[counter] = element;

		}
	};
	T flatch()
	{
		return stackPtr[counter];
	};
};

void main()
{
	Stack <int> stack(10);
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);
	stack.push(70);
	stack.push(80);
	stack.push(90);
	stack.push(100);
	stack.push(110);
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.flatch() << std::endl;
}