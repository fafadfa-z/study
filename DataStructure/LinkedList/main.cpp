#include<iostream>

#include "simple.h"
#include "circle.h"



void funSim()
{
	Simple s({ 1,2,3,4,5,6 });

	s.display();

	s.addBegin(77);
	s.addEnd(56);

	s.display();

}


void funCir()
{
	Circle c({1,2,3,4,5});

	c.add(55);
}


int main()
{
	funCir();


	

	
	return 1;
}


