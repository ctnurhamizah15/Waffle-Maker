//Group members: 
//Harithza Assikin binti Zaharuddin (60894)
//Siti Nurhamizah Raim (62591)
//Shalin Binti Shaheezam Khan(63776)
//Yomna Abobakr Ahmed Salem (63918).
//Date this program was finished : 4/18/2018
//This program is to make an order at a waffle shop.
#include<iostream> // header file
#include<iomanip> // header file
#include<stdio.h> // header file
#include<stdlib.h> // header file
#include<cctype>
#include<cstring>
#include<ctime>

#define DAILY_PIECES 200
using namespace std;

unsigned int count_waffle = 0;	// to count how many waffle sold
unsigned int count_receipt_no = 1;	//for receipt no purpose
int total_count_waffle = DAILY_PIECES;

struct Waffle_Receipt
{
	int waffle_type;
	int soft_crispy;
	int waffle_flavor;
	double price;

}waffle_receipt[ 3 ];

struct Waffle
{
	int wafflename;
	int numwaffletype;
	int flavour;
	double price;
}waffle[6];


struct Waffle_List
{
	int receipt_no;
	int waffle;
	int bool_of_crispy;
	int additional_flavor;
	double price_per_piece;
	int type;
	Waffle_List *link;
};

Waffle_List *tempnode, *head, *tail;
Waffle_List *first,*last;

class waffle{ //Struct for the different functions used in the program
public:
int Menu ();	//main menu function
int main_menu();
int sort();		//sort by the name and waffle type
int sortorder();	//sort by the order amount
int Waffle_Order_Details();	//the summary of the receipt 
int Daily_Summary ();	//the daily summary report
void Undo_Function();	//reverse the receipt made
void print_array();		//display the array
void deepcopy();		//deep copy for the array from a linked list
void Take_Order();		//take order
void Search_receipt();	//view a particular receipt
void insertion_sort();	//sort the waffle name and their type ascendingly
void insertion_sort0(); //sort the waffle name and their type descendingly
void insertion_sortorder1();//ascending sort for the order amount
void insertion_sortorder2();//descending sort for the order amount
void Preset_Data(); //you can delete this function and function body for using the software
};

int waffle::main_menu() //The main menu's function
{
	system("cls"); // to clear the screen
	int choice;
	int confirm_undo;
	int var_1 = 0;
	int var_2 = 0;
	unsigned int respond_value = 0;

	Preset_Data(); 
	do
	{
	
	cout<<setw(20)<<"\n\n\t\t\t\t\t\t Welcome to Daisy's Waffles!! "<<endl; // The menu to be displayed
	cout<<"\t\t\t*************************************************************************************"<<endl;
	cout<<"\t\t\t[                                 1 Waffle Menu                                     ]"<<endl;
	cout<<"\t\t\t[                                 2 Take Order                                      ]"<<endl;
	cout<<"\t\t\t[                                 3 Delete Order                                    ]"<<endl;
	cout<<"\t\t\t[                                 4 Ordering Details                                ]"<<endl;
	cout<<"\t\t\t[                                 5 Order Summary                                   ]"<<endl;
	cout<<"\t\t\t[                                 6 Search Receipt                                  ]"<<endl;
	cout<<"\t\t\t[                                 7 Sort by name                                    ]"<<endl;
	cout<<"\t\t\t[                                 8 Sort by order number                            ]"<<endl;
	cout<<"\t\t\t[                                 9 Exit                                            ]"<<endl;
	cout<<"\t\t\t*************************************************************************************\n"<<endl;


		while (!( cin >> choice ))
		{
			cin.clear();
			cin.ignore();
			break;

		}

		cout << endl;

		switch ( choice )
		{
		case 1:
			system("cls");
			respond_value = Menu();
			var_1 = 1;
			break;

		case 2:
			if( total_count_waffle == 0 )
			{
				cout << "Waffle sold out" << endl << endl;
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				Take_Order();
			}
			var_1 = 1;
			break;

		case 3:

			do
			{
				cout << "Do you confirm to delete the latest receipt made? [ 1. Yes | 2. No ] : ";
				while( !( cin >> confirm_undo ) )
				{ 
					cin.clear();
					cin.ignore();
					cout << ":-";
				}

				if( confirm_undo == 1 )
				{
					if( head == NULL )
					{
						cout <<"There is no receipt to delete..." << endl << endl;
						system("pause");
						system("cls");
					}
					else
						Undo_Function();

					var_2 = 1;
				}
				else if( confirm_undo == 2 )
				{
					cout << "The Request has been denied." << endl << endl;
					system("pause");
					system("cls");
					var_2 = 1;
				}
				else
				{
					cout << "Invalid Input" << endl << endl;
					var_2 = 0;
				}

			}while( var_2 != 1 );

			var_1 = 1;
			break;

		case 4:
			system("cls");
			respond_value = Waffle_Order_Details();
			var_1 = 1;
			break;

		case 5:
			system("cls");
			respond_value = Daily_Summary();
			var_1 = 1;
			break;

		case 6:
			system("cls");
			Search_receipt();
			var_1 = 1;
			break;

		case 7:
			system("cls");
			sort();
			var_1 = 1;
			break;
		case 8:
			system("cls");
			sortorder();
			var_1 = 1;
			break;

		case 9:
			cout << "Program will be terminated\n" << endl;
			var_1 = 1;
			respond_value = 1;
			break;

		default:
			system( " cls " );
			var_1 = 0;
		}

	}while ( ( var_1 != 1 ) || ( respond_value != 1 ) );

	return 0;
}

int waffle::Menu() //Function for displaying the waffle menu
{
	system("cls"); // to clear the screen
	char a; // used to store users key in

	cout<<"\n\n\t\t*************************WAFFLE MENU *********************"<<endl<<endl; // Menu to be displayed
	cout<<"________________________________________________________________________________________"<<endl;
	cout<<"|Waffle Type	                |  Crispy(RM)   |   Soft(RM)  |    Extra Charge (RM)   |"<<endl;
	cout<<"|_______________________________|_______________|_____________|________________________|"<<endl;
	cout<<"| 1.American                    |    12.00      |     10.00   |     Add RM 1.20        |"<<endl;
	cout<<"| 2.Belgium                     |    16.00      |     14.00   |    for additional      |"<<endl;
	cout<<"| 3.Rolled                      |    14.00      |     12.00   |       filling          |"<<endl;
	cout<<"|_______________________________|_______________|_____________|     Add RM 1.50        |"<<endl;
	cout<<"|                                                             |    for additional      |"<<endl;
	cout<<"|                                                             |       topping          |"<<endl;
	cout<<"|_____________________________________________________________|________________________|"<<endl;
	cout<<"| Options  :                                                                           |"<<endl;
	cout<<"| Filling : Chocolate|Butter|Kaya                                                      |"<<endl;
	cout<<"| Topping (except for Rolled Waffle) : A) Ice Cream - Vanila|Chocolate                 |"<<endl;
	cout<<"|                                      B) Fruits - Banana|Strawberry                   |"<<endl;
	cout<<"|______________________________________________________________________________________|"<<endl;
	cout<<"\n\n";

	cout<<"\nPress any key to return to main menu"<<endl; // instruction for the user
	cin>>a; // for user to key in any letter

	system("cls"); //to clear the screen
	main_menu(); // to return to main menu
}

void waffle::Take_Order() // function for ordering the waffles
{
	int payment;
	int balance;
	int piece;
	int choice;
	int type;
	int soft_crispy;
	char flavor[3][30] = {" "};
	int add_flavor;
	int total_price = 0;
	int bool_of_confirm;
	int comfirm_payment;
	int var_1 = 0;
	int var_2 = 0;
	int var_3 = 0;
	int var_4 = 0;
	int var_5 = 0;
	int var_6 = 0;
	int var_7 = 0;
	int var_8 = 0;
	int re_value;
	unsigned int counter;
	bool entry_bool = false;

	cout << fixed;
	cout << setprecision(2);
	
	do{
			
		do{
			cout << "How many pieces do you want to order? [ Maximum 3 pieces per order, input 0 for cancel the order ]: ";
		
			while( !(cin >> piece ) )
			{
				cin.clear();
				cin.ignore();
				cout << ":-";
			}

		}while( ( piece > 3) || ( piece < 0 ) );
		
		counter = 0;
		
		while( counter < piece )
		{
			
			if( piece == 0 )
			{
				break;
			}
			else
			{
				do
				{
					
					cout<< endl;
					cout << "Choose the type for your waffle no. "<< counter + 1 << " : " << endl;
					cout << "1) American" << endl;
					cout << "2) Belgium" << endl;
					cout << "3) Rolled" << endl;
					cout << "Your choice: ";
					
					do
					{
						while ( !( cin >> type ) )
						{
							cin.clear();
							cin.ignore();
							cout << ":-";
						}

						waffle_receipt[ counter ].waffle_type = type;

						switch( type )
						{
						case 1:
							waffle_receipt[ counter ].price = 10;
							var_1 = 1;
							break;

						case 2:
							waffle_receipt[ counter ].price = 15;
							var_1 = 1;
							break;

						case 3:
							waffle_receipt[ counter ].price = 12;
							var_1 = 1;
							break;

						default:
							cout << ":-" ;
							int var_1 = 0;
						}

					}while( var_1 != 1 ); //for waffle type


					
					cout << endl;
					cout << "Soft or Crispy: [ 1. Crispy | 2. Soft ]: ";
					
					do
					{ 
						while( !( cin >> soft_crispy ) )
						{
							cin.clear();
							cin.ignore();
							cout << ":-";
						}
				
						switch ( soft_crispy )
						{
						case 1:
							waffle_receipt[ counter ].soft_crispy = 1;
							var_2 = 1;
							break;

						case 2:
							waffle_receipt[ counter ].soft_crispy = 0;

							if( waffle_receipt[ counter ].waffle_type == 1 )
							{
								waffle_receipt[ counter ].price -= 1;
							}
							else
							{
								waffle_receipt[ counter ].price -= 2;
							}

							var_2 = 1;
							break;

						default:
							cout << ":-" ;
							var_2 = 0;
						}

					}while( var_2 != 1 );  //for soft or crispy

					cout << endl;

					
					cout << "How many flavor do you want to add? [ Maximum 3 flavors ]" << endl;
					cout << "1. Only 1 Flavor  [ Free ]" << endl;
					cout << "2. Only 2 Flavors [ Extra Charge RM 1.00 ]" << endl;	
					cout << "3. All Flavors!   [ Extra Charge RM 2.00 ]" << endl;
					
					do
					{
						cout << "How Many : ";

						while( !( cin >> add_flavor ) )
						{
							cin.clear();
							cin.ignore();
							cout << ":-";
						}
				
						cout << endl;

						switch ( add_flavor )
						{
						case 1:
							
							waffle_receipt[ counter ].waffle_flavor = 0;

							
							cout << "Choose your flavor" << endl;
							cout << "1. Chocolate" << endl;
							cout << "2. Butter" << endl;
							cout << "3. Kaya" << endl;
							
							do
							{
								cout << "Option : ";
								while( !(cin >> choice))
								{
									cin.clear();
									cin.ignore();
									cout << ":-";
								}
							
								if( choice == 1 )
								{
									strcpy( flavor[ counter ], "Chocolate           " );
									var_7 = 1;
								}
								else if( choice == 2 )
								{
									strcpy( flavor[ counter ], "Butter              " );
									var_7 = 1;
								}
								else if( choice == 3 )
								{
									strcpy( flavor[ counter ], "Kaya                " );
									var_7 = 1;
								}
								else
									var_7 = 0;

							}while( var_7 != 1 );

							var_3 = 1;
							break;
						
						case 2:
							waffle_receipt[ counter ].waffle_flavor = 1;
							waffle_receipt[ counter ].price += 1;

							
							cout << "Choose your flavor" << endl;
							cout << "1. Chocolate and Butter" << endl;
							cout << "2. Chocplate and Kaya" << endl;
							cout << "3. Butter and Kaya" << endl;
								
							do
							{
								cout << "Option : ";
								while( !( cin >> choice ) )
								{ 
									cin.clear();
									cin.ignore();
									cout << ":-";
								}

								if( choice == 1 )
								{
									strcpy( flavor[ counter ], "Chocolate and Butter" );
									var_8 = 1;
								}
								else if( choice == 2 )
								{
									strcpy( flavor[ counter ], "Chocolate and Kaya  " );
									var_8 = 1;
								}
								else if ( choice == 3 )
								{
									strcpy( flavor[ counter ], "Butter and Kaya     " );
									var_8 = 1 ;
								}
								else
									var_8 = 0;

							}while( var_8 != 1 );

							var_3 = 1;
							break;

						case 3:
							waffle_receipt[ counter ].waffle_flavor = 2;
							waffle_receipt[ counter ].price += 2 ;

							cout << "You choose All the Flavors!" << endl;
							
							strcpy( flavor[ counter ], "All Flavor          " );
							
							var_3 = 1;
							
							break;
							

						default:
							cout << "Invalid Input" << endl << endl;
							var_3 = 0;
						}


					}while( var_3 != 1 );   // for flavors


						cout << endl;
						cout << "________________________________________________________" << endl << endl;
						cout << "Waffle No." << counter + 1 << " Order :  ";   

						switch ( type )    // display waffle type
						{
						case 1:
							cout << "American [ X ]\tBelgium [   ]\tRolled[   ]" << endl;
							break;

						case 2:
							cout << "American [   ]\tBelgium [ X ]\tRolled [   ]" << endl;
							break; 

						case 3:
							cout << "American [   ]\tBelgium [   ]\tRolled [ X ]" << endl;
							break;
					
						default:
							cout << "Error" << endl;
						}

						cout << endl;

						cout << "Type: ";  // display soft or crispy

						if( soft_crispy == 1 )
							cout << " Crispy [ X ]\tSoft[   ]" << endl;
						else
							cout << " Crispy [   ]\tSoft[ X ]" << endl;

						cout << endl;

						cout << "Flavors: " << flavor[ counter ] << endl;  //display flavor chosen
						cout << "Additional Flavor: " << waffle_receipt [ counter ].waffle_flavor << "\n" << endl;   //display how much flavor the customer add
						cout << "Confirm Waffle no." << counter + 1 << " Order? [ Enter 1 for confirm ] : ";  // confirm the no.x of waffle
						
						while( !( cin >> bool_of_confirm ) )
						{
							cin.clear();
							cin.ignore();
							cout << ":-";
						}


						if ( bool_of_confirm == 1 ) // if confirm, counter of the array increment by 1
						{
							counter = counter + 1;
							system("cls");
							var_4 = 1;
						}
						else					// else, all values deleted, remain the same counter to choose again
						{
							cout << "The order of this waffle was cancelled...\n" << endl;

							waffle_receipt[ counter ].waffle_type = 0;
							waffle_receipt[ counter ].soft_crispy = 0;
							waffle_receipt[ counter ].waffle_flavor = 0;
							waffle_receipt[ counter ].price = 0;
							
							counter = counter + 0;

							system("cls");
							var_4 = 0;
						}

					}while( var_4 != 1 );
			}
		}

		do{
			system("cls");

			if( piece == 0 )
			{
				var_5 = 1; //Exit the loop, due to no waffle made in this receipt
			}
			else
			{
				cout << "Waffle Order" << "\t\t" << "Type" << "\t\t" << "Flavors" << "\t\t\t" << "Price [RM]" << endl;
				cout << "=================================================================================================\n" << endl;

				for( counter = 0; counter < piece ; counter ++ )
				{
					
					if( waffle_receipt [ counter ].waffle_type == 1 )
						cout << "American" << "\t\t";
					else if( waffle_receipt [ counter ].waffle_type == 2 )
						cout << "Belgium " << "\t\t";
					else  
						cout << "Rolled  " << "\t\t";

					if( waffle_receipt [ counter ].soft_crispy == 1 )
						cout << "Crispy  "<< "\t";
					else
						cout << "Soft    "<< "\t";

					cout << flavor [ counter ] << "\t";
					cout << waffle_receipt [ counter ].price << endl;

				}

				for( int i = 0; i < 3; i ++ )
				{
					total_price += waffle_receipt [ i ].price;
				}

				cout << "\n=================================================================================================" << endl;
				cout << "Total Amount to pay is RM " << total_price << ".00" << endl;
				cout << "Confirm Payment? [ 1. Yes | 2. No ] : ";
				
				do{
					while( !( cin >> choice ) )
					{
						cin.clear();
						cin.ignore();
						cout << ":-";
					}

					if( choice == 1 || choice == 2 )
						entry_bool = true;
					else
						entry_bool = false;

				}while( entry_bool != true );
				

				switch( choice )
				{
				case 1:

					for( counter = 0; counter < piece; counter++ )
					{
						tempnode = new Waffle_List;
						
						tempnode->receipt_no = count_receipt_no;
						tempnode->waffle = waffle_receipt [ counter ].waffle_type;
						tempnode->bool_of_crispy = waffle_receipt [ counter ].soft_crispy;
						tempnode->additional_flavor = waffle_receipt [ counter ].waffle_flavor;
						tempnode->price_per_piece = waffle_receipt [ counter ].price;
						
						tempnode->link = NULL;

						if(waffle_receipt [ counter ].waffle_type==1)
						{
							if(waffle_receipt [ counter ].soft_crispy==1)
							{
								tempnode->type=1;

							}
							else 
							{
								tempnode->type=2;
							}
						}
						else if(waffle_receipt [ counter ].waffle_type==2)
						{
							
							if(waffle_receipt [ counter ].soft_crispy==1)
							{
								tempnode->type=3;

							}
							else 
							{
								tempnode->type=4;
							}
						}

                        else if(waffle_receipt [ counter ].waffle_type==3)
						{
							
							if(waffle_receipt [ counter ].soft_crispy==1)
							{
								tempnode->type=5;

							}
							else 
							{
								tempnode->type=6;
							}
						}

						if( head == NULL )
						{
							head = tempnode;
							tail = tempnode;
						}
						else
						{
							tail->link = tempnode;
							tail = tempnode;
						}

					}

					count_receipt_no ++;
					count_waffle += piece;
					total_count_waffle -= piece;

					cout << endl;
					
					do{
						cout << "\nEnter the amount of payment: RM ";
						
						while( !( cin >> payment ) )
						{
							cin.clear();
							cin.ignore();
							cout << ":-";
						}

						if( payment >= total_price )
						{
							balance = payment - total_price;

							cout << "\nTotal Amount of Pay: RM " << total_price << ".00" << endl;
							cout << "Total Payment: RM " << payment << ".00" << endl << endl;
							cout << "**Change: RM " << balance << ".00" << endl << endl;
						}
						else
							cout << "Insufficient payment!!" << endl << endl;

					}while( payment < total_price );

					cout << "*Thank You Very Much*" << endl;
					
					var_5 = 1;
					break;

				case 2:
					cout << "The order was cancelled\n" << endl;
					var_5 = 1;
					break;

				default:
					cout << "Invalid Input" << "\n" << endl;
					var_5 = 0;

				}
			}

		}while( var_5 != 1 );

		cout << "Next Order? [ 1. Yes | 2. No ] : ";
		
		while( !( cin >> choice ) )
		{
			cin.clear();
			cin.ignore();
			cout << ":-";
		}

		if( choice == 1 )
		{
			var_6 = 0;
			total_price = 0;
			system("cls");
		}
		else
		{
			var_6 = 1;
			total_price = 0;
			system("cls");
		}

		for( counter = 0 ; counter < 3; counter ++ )
		{
			waffle_receipt[ counter ].waffle_type = 0;
			waffle_receipt[ counter ].soft_crispy = 0;
			waffle_receipt[ counter ].waffle_flavor = 0;
			waffle_receipt[ counter ].price = 0;
		}

		}while( var_6 != 1 );

}

int waffle::Waffle_Order_Details() // function for viewing the order
{
	double total_price = 0;
	int counter = 0;

	Waffle_List *current;

	current = head;
	
	if( current == NULL )
		cout << "Empty. Please create a receipt..." << endl << endl;
	else
	{
		cout << fixed;
		cout << setprecision (2);
		
		cout << "No" << "\t" << "Waffle Name" << "\t" << "Waffle Type" << "\t" << "Additional Flavor" << "\t" << "Price [ RM }" << endl;
		cout << "=============================================================================================================" << endl << endl;

		while( current != NULL )
		{
			if( current->receipt_no != counter )
				{
					counter++;
					cout << current->receipt_no << "\t";
				}
			else
			{
				cout << "\t";
			}

			if( current->waffle == 1 )
				cout << "American" << "\t";
			else if( current->waffle == 2 )
				cout << "Belgium " << "\t";
			else
				cout << "Rolled  " << "\t";

			if( current->bool_of_crispy == 1 )
				cout << "Crispy" << "\t\t\t";
			else
				cout << " Soft " << "\t\t\t";

			cout << current->additional_flavor << "\t\t";
			cout << current->price_per_piece;
			cout << endl;

			total_price = total_price + current->price_per_piece;

			if( current == tail )
				break;
			else
			{
				current = current->link;
				if( current->receipt_no != counter ) 
					cout << "_________________________________________________________________________" << endl << endl;
			}
			 
		}
		
		cout << "_________________________________________________________________________" << endl;
		cout << endl << "Total Amount = RM " << total_price << endl << endl;
	}

	
	system("pause");
	system("cls");

	return 0;

}

int waffle::Daily_Summary()
{
	int amountT=0;//Total amount (RM)
	int total1=0;//total amount of american waffle crispy
	int total2=0;//total amount of american waffle soft
	int total3=0;//total amount of belgium waffle  crispy
	int total4=0;//total amount of belgium waffle  soft
	int total5=0;//total amount of rolled waffle crispy
	int total6=0;//total amount of rolled waffle soft
	int flvr1=0;//total flavour added to american waffle 
	int flvr2=0;//total flavour added to belgium waffle
	int flvr3=0;//total flavour added to rolled waffle
	double priceT1=0;//total amount of american waffle
	double priceT2=0;//total amount of belgium waffle
	double priceT3=0;//total amount of rolled waffle

	Waffle_List *cu;
	cu = head;


	cout << fixed;
	cout << setprecision(2);

	cout << setw(46) << "Waffle Shop" << endl;
	cout << setw(50) << "Daily Sales Summary" << endl;
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout << "Date:" <<  ltm->tm_mday ;
	cout << "//" << 1 + ltm->tm_mon;
	cout << "//" << 1900 + ltm->tm_year<< endl;
	int n;
	
	for(n=0;n<=79;n++)
	{
		cout <<"_";
	}
	cout << "\n";
	cout << "NO"<<setw(20) << "Waffle Type" << setw(18) << "Type" << setw(25) << "Extra flavour" << setw(14) << "Amount(RM)" << endl;
	cout << setw(45) << "Crispy | Soft "<< endl;
	
	for( n = 0; n <= 79; n++ )
	{
		cout << "_";
	}
	cout << "\n";

	while( cu != NULL )
	{

		if(cu->type == 1 || cu->type == 2)
		{
			if (cu->type == 1)
			{
				total1 += 1;
				flvr1 += cu->additional_flavor;
				priceT1 += cu->price_per_piece;
			}
			else
			{
				total2 += 1;
				flvr1 += cu->additional_flavor;
				priceT1 += cu->price_per_piece;
			}

		}
		else if( cu->type == 3 || cu->type == 4 )
		{
			if ( cu->type == 3 ) 
			{
				total3 += 1;
				flvr2 += cu->additional_flavor;
				priceT2 += cu->price_per_piece;
			}
				
			else
			{
				total4 += 1;
				flvr2 += cu->additional_flavor;
				priceT2 += cu->price_per_piece;
			}
				
			
		}
		else if(cu->type == 5 || cu->type == 6)
		{
			
			if (cu->type == 5)
			{
				total5 += 1;
				flvr3 += cu->additional_flavor;
				priceT3 += cu->price_per_piece;
			}
				
			else
			{
				total6 += 1;
				flvr3 += cu->additional_flavor;
				priceT3 += cu->price_per_piece;
			}
				
			
		}
	
		cu = cu->link;
	}
	cout <<"1"<< setw(25) << "American waffle"<< setw(8) << total1 << setw(8) << total2<< setw(15) << flvr1 << setw(18) << "RM" << priceT1 << endl;
	cout <<"2"<< setw(24) << "Belgium waffle" << setw(9) << total3 << setw(8) << total4<< setw(15) << flvr2 << setw(18) << "RM" << priceT2 << endl;
	cout <<"3"<< setw(23) << "Rolled waffle"  << setw(10) << total5 << setw(8) << total6<< setw(15) << flvr3 << setw(18) << "RM" << priceT3 << endl;
	 
	for(n=0;n<=79;n++)
	{
		cout <<"_";
	}
	cout << "\n";

	amountT = priceT1 + priceT2 + priceT3;

	cout << "TOTAL" << setw(70) << "RM" << amountT << ".00" << endl;
	cout << "Total Waffle : " << count_waffle << endl;
	cout << "Total Waffle Left: " << total_count_waffle << endl << endl;

	system("pause");
	system("cls");
	
	return 0;
}

void waffle::Search_receipt()
{
	bool found = false;
	int searchreceipt;
	int waffle_number = 0;
	double total_receipt_price = 0;

	Waffle_List *temp;
	temp = head;
	
	cout << fixed;
	cout << setprecision (2);

	cout << "Which receipt you want to search?" << endl;
	
	while( !( cin >> searchreceipt) )
	{
		cin.clear();
		cin.ignore();
		cout << ":-";
	}

	system("cls");

	found = false;
	
	cout << fixed;
	cout << setprecision(2);

	cout << endl;
	cout << "Receipt No #" << searchreceipt << endl << endl;
	cout << "No" << "\t" << "Waffle Name" << "\t" << "Waffle Type" << "\t" << "Additional Flavor" << "\t" << "Price [ RM }" << endl;
	cout << "=============================================================================================================" << endl << endl;

    while (temp != NULL)
    {

		if(temp->receipt_no == searchreceipt)
		{
			waffle_number ++;

			cout << waffle_number << "\t";

			if( temp->waffle == 1 )
				cout << "American" << "\t";
			else if( temp->waffle == 2 )
				cout << "Belgium " << "\t";
            else
				cout << "Rolled  " << "\t";

			if( temp->bool_of_crispy == 1 )
				cout << "Crispy" << "\t\t\t";
			else
				cout << " Soft " << "\t\t\t";

			cout << temp->additional_flavor << "\t\t";
            cout << temp->price_per_piece << endl;
			
			total_receipt_price += temp->price_per_piece;

            found = true;
		}
		
		if (temp == tail)
			break;
		else
			temp = temp->link;
        
	}

	cout << "\n=============================================================================================================" << endl;
	cout << "Total(RM)" << setw(60) << total_receipt_price << endl;
	cout << endl;

	if (found == false)
	{
	    system("cls");
	    cout << "Receipt not found" << endl;
	}
	
	waffle_number = 0;

	system("pause");
	system("cls");

}

int waffle::sort()
{
		deepcopy();
	unsigned int i;
	int choice;
    int j ,tmp1,tmp2,tmp3; 
	double tmp4;

	cout << "Do you want to sort the name and the waffle type by ascending or descending? [ 1. Ascending | 2.Descending] : ";
	
	while( !(cin >> choice))
	{
		cin.clear();
		cin.ignore();
		cout << ":-";
	}

	if( choice == 1 )
			for (i = 1; i < 6; i++) 
	{
		j = i;
		
		while ( j > 0 && waffle[j - 1].wafflename > waffle[j].wafflename ) 
		{
			tmp1 = waffle [j].wafflename;
			tmp2 = waffle [j].numwaffletype;
			tmp3 = waffle [j].flavour;
			tmp4 = waffle [j].price;

			waffle [j].wafflename = waffle [j - 1].wafflename;
			waffle [j].numwaffletype = waffle [j - 1].numwaffletype;
			waffle [j].flavour = waffle [j - 1].flavour ;
			waffle [j].price = waffle [j - 1].price ;

			waffle [j - 1].wafflename = tmp1;
			waffle [j - 1].numwaffletype = tmp2;
			waffle [j - 1].flavour = tmp3;
			waffle [j - 1].price = tmp4;
			j--;
			
		}
		
	}
	else
		for (i = 1; i < 6; i++) 
	{
		j = i;
		
		while ( j > 0 && waffle[j - 1].wafflename  < waffle[j].wafflename ) 
		{
			tmp1 = waffle [j].wafflename;
			tmp2 = waffle [j].numwaffletype;
			tmp3 = waffle [j].flavour;
			tmp4 = waffle [j].price;

			waffle [j].wafflename = waffle [j - 1].wafflename;
			waffle [j].numwaffletype = waffle [j - 1].numwaffletype;
			waffle [j].flavour = waffle [j - 1].flavour ;
			waffle [j].price = waffle [j - 1].price ;

			waffle [j - 1].wafflename = tmp1;
			waffle [j - 1].numwaffletype = tmp2;
			waffle [j - 1].flavour = tmp3;
			waffle [j - 1].price = tmp4;

			j--;
			
		}
		
	}

	print_array();
	
	for( i = 0; i < 6; i++ )	// clearing data in the array list
	{
		waffle [i].wafflename = 0;
		waffle [i].numwaffletype = 0;
		waffle [i].flavour = 0;
		waffle [i].price = 0;
	}
	
	system("pause");
	system("cls");

	return 0;
}


int waffle::sortorder()
{
	int choice;
	unsigned int i;
	int j, tmp1, tmp2, tmp3;
	double tmp4;

	deepcopy();
	
	do
	{
		cout << "Do you wish to view in ascending sort or decending sort? [ 1. Ascending | 2. Decending ] : ";
		
		while( !( cin >> choice ) )
		{
			cin.clear();
			cin.ignore();
			cout << ":-";
		}

		if( choice == 1 )
		    for( i = 1; i < 6; i++ ) 
		{
			
			j = i;
			while ( j > 0 && waffle [j - 1].numwaffletype  > waffle  [j].numwaffletype ) 
			{
			
			tmp1 = waffle [j].wafflename;
			tmp2 = waffle [j].numwaffletype;
			tmp3 = waffle [j].flavour;
			tmp4 = waffle [j].price;
			waffle [j].wafflename = waffle [j - 1].wafflename;
			waffle [j].numwaffletype = waffle [j - 1].numwaffletype;
			waffle [j].flavour = waffle [j - 1].flavour ;
			waffle [j].price = waffle [j - 1].price ;
			waffle [j - 1].wafflename = tmp1;
			waffle [j - 1].numwaffletype = tmp2;
			waffle [j - 1].flavour = tmp3;
			waffle [j - 1].price = tmp4;

			j--;
			
			}
		}
		else if( choice == 2 )
			for ( i = 1; i < 6; i++ ) 
		{
			j = i;
			while (j > 0 && waffle [j - 1].numwaffletype  < waffle  [j].numwaffletype ) 
			
			{
			
			tmp1 = waffle [j].wafflename;
			tmp2 = waffle [j].numwaffletype;
			tmp3 = waffle [j].flavour;
			tmp4 = waffle [j].price;

			waffle [j].wafflename = waffle [j - 1].wafflename;
			waffle [j].numwaffletype = waffle [j - 1].numwaffletype;
			waffle [j].flavour = waffle [j - 1].flavour ;
			waffle [j].price = waffle [j - 1].price ;

			waffle [j - 1].wafflename = tmp1;
			waffle [j - 1].numwaffletype = tmp2;
			waffle [j - 1].flavour = tmp3;
			waffle [j - 1].price = tmp4;

			j--;
			
			}
		}
		else 
			cout << "Invalid Input" << endl << ":-";
	
	}
	while( choice != 1 && choice != 2 );

	print_array();
	system("pause");

	for( i = 0; i < 6; i++ )   // clearing data in the array list
	{
		waffle [i].wafflename = 0;
		waffle [i].numwaffletype = 0;
		waffle [i].flavour = 0;
		waffle [i].price =  0;
	}

	system("cls");

	return 0;
}


void waffle::Undo_Function() // function to delete a part of the order
{
	unsigned int track_number;

	Waffle_List *current, *trail_current;

	track_number = count_receipt_no - 1;

	current = new Waffle_List;
	trail_current = new Waffle_List;

	if( head == NULL )
	{
		cout << "The receipt list is empty, undo function is denied." << endl  << endl;
	}
	else
	{
		if( ( head == tail ) && ( head->receipt_no == track_number ) )
		{
			current = head;

			head = NULL;
			tail = NULL;

			delete current;

			cout << "The latest receipt has been deleted." << endl << endl;
			count_receipt_no --;
			count_waffle --;
			total_count_waffle ++;;
		}
		else
		{
			current = head->link;
			trail_current = head;

			while( current != NULL )
			{
				if( ( current == tail ) && ( current->receipt_no == track_number ) )
				{
					tail = trail_current;
					tail->link = NULL;

					delete current;
					count_waffle--;
					total_count_waffle ++;

					if ( (trail_current == head ) && ( trail_current->receipt_no == track_number ) )
					{
						head = NULL;
						tail = NULL;
						delete trail_current;
						count_waffle --;
						total_count_waffle ++;
						break;
					}
					else
					{
						current = new Waffle_List;
						current = head->link;
						trail_current = head;
					}

				}
				else
				{
					current = current->link;
					trail_current = trail_current->link;
				}
			}

			cout << "The latest receipt has been deleted." << endl << endl;
			count_receipt_no --;
		}
	}

	system("pause");
	system("cls");
}

void waffle::deepcopy()		//deep copying the data from the linked list to the array
{
	Waffle_List *trvptr;
	trvptr = head;

	while(trvptr != NULL)
	{
		if(trvptr->type == 1)
		{
			
			waffle[0].numwaffletype += 1;
			waffle[0].flavour = trvptr->additional_flavor + waffle[0].flavour;
			waffle[0].price = trvptr->price_per_piece + waffle[0].price;
		}
		else if(trvptr->type == 2)
		{
			waffle[1].numwaffletype += 1;
			waffle[1].flavour = trvptr->additional_flavor + waffle[1].flavour;
			waffle[1].price = trvptr->price_per_piece + waffle[1].price;
		}
		else if(trvptr->type == 3)
		{
			
			waffle[2].numwaffletype += 1;
			waffle[2].flavour = trvptr->additional_flavor + waffle[2].flavour;
			waffle[2].price = trvptr->price_per_piece + waffle[2].price;
		}
		else if(trvptr->type == 4)
		{
			
			waffle[3].numwaffletype += 1;
			waffle[3].flavour = trvptr->additional_flavor + waffle[3].flavour;
			waffle[3].price = trvptr->price_per_piece + waffle[3].price;
		}
		else if(trvptr->type == 5)
		{
			
			waffle[4].numwaffletype += 1;
			waffle[4].flavour = trvptr->additional_flavor + waffle[4].flavour;
			waffle[4].price = trvptr->price_per_piece + waffle[4].price;
		}
		else if(trvptr->type == 6)
		{
			
			waffle[5].numwaffletype += 1;
			waffle[5].flavour = trvptr->additional_flavor + waffle[5].flavour;
			waffle[5].price = trvptr->price_per_piece + waffle[5].price;
		}

		trvptr = trvptr->link;
	}
	waffle[0].wafflename = 1;
	waffle[1].wafflename = 2;
	waffle[2].wafflename = 3;
	waffle[3].wafflename = 4;
	waffle[4].wafflename = 5;
	waffle[5].wafflename = 6;
}

void waffle::print_array()  //display the sorted receipt
{

	cout << fixed;
	cout << setprecision (2);
	cout <<setw(46)<<"\t\tWaffle Shop"<< endl;
	cout <<setw(50)<<"\t\tDaily Sales Summary"<< endl;
	
	time_t now = time(0); //display the time
	tm *ltm = localtime(&now);

	cout << "Date:"<<  ltm->tm_mday ;
	cout << "/"<< 1 + ltm->tm_mon;
	cout << "/"<< 1900 + ltm->tm_year<< endl;

	cout << "No" << "\t\t" << "Waffle Name" << "\t\t" << "Order Number" << "\t" << "Extra flavour" << "\t\t" << "Amount(RM)" << endl;
	cout << "=============================================================================================================" << endl << endl;

	int j;
	int Total_price;
	
	for (j=0; j<6;j++)
	{	
		for (j=0; j<6;j++)
		{
			if(waffle[j].wafflename==1)
			{
				cout <<j+1<< "\t\t" <<"American Waffle (crispy) ";
				cout<< "\t" <<waffle[j].numwaffletype<< "\t" <<waffle[j].flavour<< "\t\t" <<"RM"<<waffle[j].price << endl;
			}
			else if(waffle[j].wafflename==2)
			{
				cout <<j+1<< "\t\t" <<"American Waffle (soft) ";
				cout<< "\t\t" <<waffle[j].numwaffletype<< "\t" <<waffle[j].flavour<< "\t\t" <<"RM"<<waffle[j].price <<endl;
			}
			else if(waffle[j].wafflename==3)
			{
				cout <<j+1<< "\t\t" <<"Belgium Waffle (crispy) ";
				cout<< "\t" <<waffle[j].numwaffletype<< "\t" <<waffle[j].flavour<< "\t\t" <<"RM"<<waffle[j].price <<endl;
			}
			else if(waffle[j].wafflename==4)
			{
				cout <<j+1<< "\t\t" <<"Belgium Waffle (soft) ";
				cout<< "\t\t" <<waffle[j].numwaffletype<< "\t" <<waffle[j].flavour<< "\t\t" <<"RM"<<waffle[j].price <<endl;
			}
			else if(waffle[j].wafflename==5)
			{
				cout <<j+1<< "\t\t" <<"Rolled Waffle (crispy) ";
				cout<< "\t\t" <<waffle[j].numwaffletype<< "\t" <<waffle[j].flavour<< "\t\t" <<"RM"<<waffle[j].price << endl;
			}
			else if(waffle[j].wafflename==6)
			{
				cout <<j+1<< "\t\t" <<"Rolled Waffle(soft) ";
				cout<< "\t\t" <<waffle[j].numwaffletype<< "\t" <<waffle[j].flavour<< "\t\t" <<"RM"<<waffle[j].price<<endl;
			}
		}
	}

	Total_price=waffle[0].price+waffle[1].price+waffle[2].price+waffle[3].price+waffle[4].price+waffle[5].price;
		
	cout << "=============================================================================================================" << endl;
	cout <<"TOTAL"<<setw(69)<<"RM"<<Total_price<<".00"<<endl;
	cout << "Total Waffle : " << count_waffle << endl;
	cout << "Total Waffle Left: " << total_count_waffle << endl << endl;

}


void waffle::Preset_Data() // Preset Data
{
	struct Preset_Waffle
	{
		int receipt_numbering;
		int waffle_type;
		int c_s;
		int add_flavor;
		double price_of_this_waffle;
		int type;
	};

	Preset_Waffle preset_array [8];

	preset_array[0].receipt_numbering = count_receipt_no;
	preset_array[0].waffle_type = 1;
	preset_array[0].c_s = 1;
	preset_array[0].add_flavor = 0;
	preset_array[0].price_of_this_waffle = 10.00;
	preset_array[0].type=1;

	preset_array[1].receipt_numbering = count_receipt_no;
	preset_array[1].waffle_type = 1;
	preset_array[1].c_s = 0;
	preset_array[1].add_flavor = 2;
	preset_array[1].price_of_this_waffle = 11.00;
	preset_array[1].type=2;

	count_receipt_no ++; // first receipt made

	preset_array[2].receipt_numbering = count_receipt_no;
	preset_array[2].waffle_type = 2;
	preset_array[2].c_s = 1;
	preset_array[2].add_flavor = 1;
	preset_array[2].price_of_this_waffle = 16.00;
	preset_array[2].type=3;

	count_receipt_no ++; // second receipt made

	preset_array[3].receipt_numbering = count_receipt_no;
	preset_array[3].waffle_type = 3;
	preset_array[3].c_s = 0;
	preset_array[3].add_flavor = 1;
	preset_array[3].price_of_this_waffle = 11.00;
	preset_array[3].type=6;

	preset_array[4].receipt_numbering = count_receipt_no;
	preset_array[4].waffle_type = 3;
	preset_array[4].c_s = 1;
	preset_array[4].add_flavor = 0;
	preset_array[4].price_of_this_waffle = 12.00;
	preset_array[4].type=5;

	preset_array[5].receipt_numbering = count_receipt_no;
	preset_array[5].waffle_type = 2;
	preset_array[5].c_s = 0;
	preset_array[5].add_flavor = 0;
	preset_array[5].price_of_this_waffle = 13.00;
	preset_array[5].type=4;

	count_receipt_no ++; // third receipt made

	preset_array[6].receipt_numbering = count_receipt_no;
	preset_array[6].waffle_type = 1;
	preset_array[6].c_s = 0;
	preset_array[6].add_flavor = 2;
	preset_array[6].price_of_this_waffle = 11.00;
	preset_array[6].type=2;

	preset_array[7].receipt_numbering = count_receipt_no;
	preset_array[7].waffle_type = 2;
	preset_array[7].c_s = 1;
	preset_array[7].add_flavor = 0;
	preset_array[7].price_of_this_waffle = 15.00;
	preset_array[7].type=3;

	count_receipt_no ++; // fourth receipt made
	count_waffle = count_waffle + 8;

	for( size_t i = 0; i < 8; i ++ )  //store the data to the link lists
	{
		tempnode = new Waffle_List;

		tempnode->receipt_no = preset_array[i].receipt_numbering;
		tempnode->waffle = preset_array[i].waffle_type;
		tempnode->bool_of_crispy = preset_array[i].c_s;
		tempnode->additional_flavor = preset_array[i].add_flavor;
		tempnode->price_per_piece = preset_array[i].price_of_this_waffle;
		tempnode->type=preset_array[i].type;

		tempnode->link = NULL;

		if( head == NULL )
		{
			head = tempnode;
			tail = tempnode;
		}
		else
		{
			tail->link = tempnode;
			tail = tempnode;
		}
	}
	
	total_count_waffle -= 8;
	//total_count_waffle = 0;   //testing for the functionality when all of the waffles has been sold out
}

