#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//linked list
struct data
{
	int item_name;
	int flavour;
	int quantity;
	data*next;
};

// Get the food ordering data  
void getData (data *head)
{	
    do{   	
     	cout << "1. Pizza\n";
	    cout << "2. Sides\n";
	    cout << "3. Beverage\n";
	    cout << "Please choose one: ";
	    cin>>head -> item_name;
	    cout<<endl;
	
	    while (head -> item_name >3)
	    {
		    cout<<"Please enter the correct number !!!"<<endl;
		    cout << "1. Pizza\n";
	        cout << "2. Sides\n";
      	    cout << "3. Beverage\n";
	        cout << "Please choose one: ";
	        cin>>head -> item_name;
	        cout<<endl;
	    }
	   
	    if (head-> item_name == 1) 
	    {
		    cout << "Flavor: 1. Hawaiian\n";
		    cout << "      : 2. Pepperoni\n";
	      	cout << "      : 3. Chicken\n";
		    cout << "      : 4. Cheese\n";
		    cout << "Enter flavour: ";
		    cin >> head->flavour;
	    }
      	else if (head-> item_name == 2) 
    	{
		    cout << "Chioce: 1. Mushroom Soup\n";
		    cout << "      : 2. Garlic Bread\n";
		    cout << "      : 3. Onion Ring\n";
		    cout << "      : 4. Popcorn Chicken\n";
		    cout << "Enter choice: ";
		    cin >> head->flavour;
	    }
	    else if (head-> item_name == 3) 
	    {
		    cout << "Chioce: 1. Cola\n";
		    cout << "      : 2. Sprite\n";
		    cout << "      : 3. Orange Juice\n";
		    cout << "      : 4. Ice Lemon Tea\n";
		    cout << "Enter choice: ";
		    cin >> head->flavour;
	    }
	    if (head -> flavour > 4)
	    {
	    	cout<<"\nPlease enter the correct number !!!"<<endl;	
		}    
    }while (head -> item_name > 3 || head -> flavour > 4);
		
	cout<<"Please enter the quantity : ";
	cin>>head -> quantity;
	cout<<endl;

	head -> next = NULL;
}

//get data for first item
data*createReceipt()
{
	data*node = new data;
	cout <<"                  ===============================================\n";
    cout << "                                WELCOME TO PIZZA MAN  \n";
	cout <<"                  ===============================================\n"; 
	cout <<"\n                                       Menu                        \n";
	cout <<"----------------------------------------------------------------------------------\n";
	cout <<"          Pizza              |          Sides            |       Beverage  \n";
	cout <<"==================================================================================\n";
    cout <<" Hawaiian Pizza    RM 20.00  | Mushroom Soup    RM 6.50  | Cola           RM 2.80\n";
	cout <<" Pepperoni Pizza   RM 20.00  | Garlic Bread     RM 5.00  | Sprite         RM 2.80\n";
    cout <<" Chicken Pizza     RM 18.00  | Onion Ring       RM 5.00  | Orange Juice   RM 5.00\n";
    cout <<" Cheese Pizza      RM 15.00  | Popcorn Chicken  RM 7.00  | Ice Lemon Tea  RM 5.00\n";
    cout <<"----------------------------------------------------------------------------------\n";
	cout<<"\nEnter data for first item : "<<endl;
	getData(node);
	return node;
}

//get data for new item
void addNewData(data*head)
{
	data*temp = head;
	
	while (temp -> next)
	{
		temp = temp -> next;
	}
	data *newNode = new data;
	cout<<"Enter data for new items : "<<endl;
	
	getData(newNode);
	temp -> next = newNode;
}

//display order for customer
void displayOrder (data*head)
{
	double price;
	data*temp = head;
	int total_quantity = 0;
	
	cout<<"Your order as below : "<<endl;
    cout<<"_______________________________________________________________"<<endl;

	while(temp)
	{   
        // display for chosen pizza	
		if (temp -> item_name == 1 && temp -> flavour == 1)
		{
			cout <<"Hawaiian Pizza";
			price = 20;
	    }
	    else if (temp -> item_name == 1 && temp -> flavour == 2)
		{
			cout <<"Pepperoni Pizza";
			price = 20;
	    }
	    else if (temp -> item_name == 1 && temp -> flavour == 3)
		{
			cout <<"Chicken Pizza";
			price = 18;
	    }
	    else if (temp -> item_name == 1 && temp -> flavour == 4)
		{
			cout <<"Cheese Pizza";
			price = 15;
	    }
	    
	     //display for chosen side dishes
	    if (temp -> item_name == 2 && temp -> flavour == 1)
		{
			cout <<"Mushroom Soup";
			price = 6.50;
	    }
	    else if (temp -> item_name == 2 && temp -> flavour == 2)
		{
			cout <<"Garlic Bread";
			price = 5;
	    }
	    else if (temp -> item_name == 2 && temp -> flavour == 3)
		{
			cout <<"Onion Ring";
			price = 5;
	    }
	    else if (temp -> item_name == 2 && temp -> flavour == 4)
		{
			cout <<"Popcorn Chicken";
			price = 7;
	    }
	    
		//display for chosen beverage
	    if (temp -> item_name == 3 && temp -> flavour == 1)
		{
			cout <<"Cola      ";
			price = 2.80;
	    }
	    else if (temp -> item_name == 3 && temp -> flavour == 2)
		{
			cout <<"Sprite     ";
			price = 2.80;
	    }
	    else if (temp -> item_name == 3 && temp -> flavour == 3)
		{
			cout <<"Orange Juice";
			price = 5;
	    }
	    else if (temp -> item_name == 3 && temp -> flavour == 4)
		{
			cout <<"Ice Lemon Tea";
			price = 5;
	    }
	    
		cout<<"\t\t\t"<<fixed<<setprecision(2)<<price<<" * "<<temp -> quantity<<" \t\t"<<fixed<<setprecision(2)<<price*temp -> quantity<<endl;
		
		temp = temp -> next;
		cout<<endl;
	} 
}

//Create payment receipt for customer
void payReceipt (data*head)
{
	double price;
	data*temp = head;
	double sub_total = 0;
	int total_items = 0;
	int total_quantity = 0;
	float total_saving = 0;
	float total = 0;
	float change = 0;
	float cash = 0;
	float rounding = 0.00;
	
	cout<<"***************Transaction Receipt******************"<<endl;
	cout<<endl;
	cout<<"           PIZZA MAN SDN BHD (1332056-P)"<<endl;
	cout<<"            55, JALAN RAMPAI NIAGA 6,"<<endl;
	cout<<"              RAMPAI BUSINESS PARK,"<<endl;
	cout<<"               53300 KUALA LUMPUR, "<<endl;
	cout<<"         WILAYAH PERSUKUTUAN KUALA LUMPUR."<<endl;
    cout<<"____________________________________________________"<<endl;

	while(temp)
	{   
        // display for chosen pizza	
		if (temp -> item_name == 1 && temp -> flavour == 1)
		{
			cout <<"Hawaiian Pizza"<<endl;
			price = 20;
	    }
	    else if (temp -> item_name == 1 && temp -> flavour == 2)
		{
			cout <<"Pepperoni Pizza"<<endl;
			price = 20;
	    }
	    else if (temp -> item_name == 1 && temp -> flavour == 3)
		{
			cout <<"Chicken Pizza"<<endl;
			price = 18;
	    }
	    else if (temp -> item_name == 1 && temp -> flavour == 4)
		{
			cout <<"Cheese Pizza"<<endl;
			price = 15;
	    }
	    
		//display for chosen side dishes
	    if (temp -> item_name == 2 && temp -> flavour == 1)
		{
			cout <<"Mushroom Soup"<<endl;
			price = 6.50;
	    }
	    else if (temp -> item_name == 2 && temp -> flavour == 2)
		{
			cout <<"Garlic Bread"<<endl;
			price = 5;
	    }
	    else if (temp -> item_name == 2 && temp -> flavour == 3)
		{
			cout <<"Onion Ring"<<endl;
			price = 5;
	    }
	    else if (temp -> item_name == 2 && temp -> flavour == 4)
		{
			cout <<"Popcorn Chicken"<<endl;
			price = 7;
	    }
	    
		//display for chosen beverage
	    if (temp -> item_name == 3 && temp -> flavour == 1)
		{
			cout <<"Cola"<<endl;
			price = 2.80;
	    }
	    else if (temp -> item_name == 3 && temp -> flavour == 2)
		{
			cout <<"Sprite"<<endl;
			price = 2.80;
	    }
	    else if (temp -> item_name == 3 && temp -> flavour == 3)
		{
			cout <<"Orange Juice"<<endl;
			price = 5;
	    }
	    else if (temp -> item_name == 3 && temp -> flavour == 4)
		{
			cout <<"Ice Lemon Tea"<<endl;
			price = 5;
	    }
	    
	    
	    
		cout<<"\t\t\t "<<fixed<<setprecision(2)<<price<<" * "<<temp -> quantity<<" \t\t"<<fixed<<setprecision(2)<<price*temp -> quantity<<endl;
		
		sub_total += price*temp -> quantity;
		total_items ++;
		total_quantity += temp -> quantity;
		temp = temp -> next;
	} 

	//rounding 
    if (fmod(sub_total*100,10) == 1 && fmod(sub_total*100,10) == 2)
    {
    	rounding = 0.00 - fmod(sub_total*100,10)/100;
	}
	else if (fmod(sub_total*100,10) == 3 || fmod(sub_total*100,10) == 4 || fmod(sub_total*100,10) == 6 || fmod(sub_total*100,10) == 7)
	{
		rounding = 0.05 - fmod(sub_total*100,10)/100;
	}
	else if (fmod(sub_total*100,10) == 8 || fmod(sub_total*100,10) == 9)
	{
		rounding = 0.10 - fmod(sub_total*100,10)/100;
	}
	
	total = sub_total + rounding;
	
	cout<<"____________________________________________________"<<endl;
	cout<<"Total Item   : "<<total_items<<"\t\t Sub Total   : "<<fixed<<setprecision(2)<<sub_total<<endl;
	cout<<"Total Qty    : "<<total_quantity<<"\t\t  Rounding   : "<<fixed<<setprecision(2)<<rounding<<endl;
	cout<<"Total Saving : "<<total_saving<<"\t\t     Total   : "<<fixed<<setprecision(2)<<total<<endl;
		cout<<setw(47)<<fixed<<setprecision(2)<<" CASH   : ";
	cout<<fixed<<setprecision(2);
	cin>>cash;
	
	
	
	while (cash<total){
	cout<<"\n       YOUR CASH IS NOT ENOUGH"<<endl;
	cout<<"\n     PLEASE PAY THE EXACT AMOUNT "<<endl;
	cout<<setw(47)<<fixed<<setprecision(2)<<" CASH   : ";
	cout<<fixed<<setprecision(2);
	cin>>cash;
	}
	
	change = cash - total;
	

	
	cout<<setw(47)<<"Change   : "<<fixed<<setprecision(2)<<change<<endl;
	cout<<endl;
	cout<<"        GOODS SOLD ARE NOT REFUNDABLE"<<endl;
	cout<<"\n                VISIT US AT "<<endl;
	cout<<"          www.facebook.com/pizzaman"<<endl;
	cout<<"       THANK YOU AND PLEASE COME AGAIN"<<endl;
	cout<<endl;	
}		
 
 
int getSize(data*head)
{
	int size = 0;
	data*temp = head;
	
	while(temp)
	{
		size++;
		temp = temp -> next;
	}
	return size;
}

//delete item from list
data* deleteData (data*head)
{
	int index;
	cout<<"Please enter the index number of the item that you want to delete : ";
	cin>>index;
	cout<<endl;
	
	if (index > getSize(head) || index <=0)
	{
		cout<<"\nInvalid Index\n";
		return head;
	}
	else if (index == 1)
	{
		head = head -> next;
		return head;
	}
	index = index - 2;
	data*temp = head;
	while (index && temp)
	{
		index--;
		temp = temp -> next;
	}
	temp -> next = temp -> next -> next;
	return head;
}

//modify data (change the quantity of selected item)
data* modify (data*head)
{
    data*temp = head;
	int index;
	int quantity;
	cout<<"Please enter the index number of the item that you want to modify : ";
	cin>>index;
    cout << "Enter the new quantity: ";
    cin >> quantity;
	
	if (index > getSize(head) || index <=0)
	{
		cout<<"\nInvalid Index!!\n\n";
		return head;
	}

	index = index - 1;

	while (index && temp)
	{
		index--;
		temp = temp -> next;
	}
	temp->quantity = quantity;
	temp -> next = temp -> next;
   
	cout<<endl;
	return head;
	
}

int main()
{
	data*head = createReceipt();
	double sub_total;
	double rounding;
	double total, total_saving, cash, change;
	int total_items, total_quantity;
	int num;
	
	do
	{
		cout<<"1. Continue to add new items"<<endl;
		cout<<"2. Delete items"<<endl;
		cout<<"3. Display order"<<endl;
		cout<<"4. Print Receipt"<<endl;
		cout<<"5. Modify"<<endl;
		cout<<"6. Exit"<<endl;
		cin>>num;
		cout<<endl;
		
		while (num != 1 && num != 2 &&num != 3 &&num != 4 && num != 5 && num != 6)
		{
		 
	    cout<<"Please enter the correct number !"<<endl;
		cout<<"1. Continue to add new items"<<endl;
	    cout<<"2. Delete items"<<endl;
		cout<<"3. Display order"<<endl;
		cout<<"4. Print Receipt"<<endl;
		cout<<"5. Modify"<<endl;
		cout<<"6. Exit"<<endl;
		cin>>num;
		cout<<endl;
		} 
		if(num == 1)
		{
			addNewData(head);
		}
		else if (num == 2)
		{
			head = deleteData(head);
		}
		else if(num == 3)
		{
			displayOrder (head);
	    }
	    else if (num == 4)
	    {
	    	payReceipt(head);
	    }
	    else if(num == 5)
	    {
	    	modify(head);
		}
	}while(num!=6);
	

}
