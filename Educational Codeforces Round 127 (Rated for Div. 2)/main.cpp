#include <iostream>
#include "VIPRoom.h"
#include "DiscountRoom.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Room* r=new Room(1234,5,80,"2021-08-06","2021-08-12");
	r->SubmitBooking();
	r->PrintStatus();
	return 0;
}