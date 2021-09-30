

using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#define MAX 300
#define LEN 100
class land
{
	public:
	int eno;	
	string owner;
	string city;
	float area;
	float price;
	long contact;
	string type;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void search();
};land l,l1;

void land::getdata(void)
{
	cout<<"Enter entry number"<<"\n";
	cin>>eno;
	cout<<"Enter owner's name"<<"\n";
	cin>>owner;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter area"<<"\n";
	cin>>area;
	cout<<"Enter price"<<"\n";
	cin>>price;
	cout<<"Enter type"<<"\n";
	cin>>type;
	cout<<"Enter contact number"<<"\n";
	cin>>contact;				
}

void land::display(void)
{
	cout<<"Owner: "<<owner<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Area: "<<area<<"\n";
	cout<<"Price: "<<price<<"\n";
	cout<<"Type: "<<type<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void land::insert()
{
	char buff[MAX];
	fstream myfile;
	myfile.open("land.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{
	    //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;

		myfile<<eno<<" "<<owner<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		myfile<<fixed<<setw(12)<<setprecision(2)<<price<<" "<<type<<" ";
		myfile<<contact<<endl;
		
	}
	myfile.close();
}

void land::record_remove()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("land.txt",ios::in);
	myfile1.open("temp_land.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the entry you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          char type[LEN];
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %ld",&eno,owner,city,&area,&price,type,&contact);
	          //cout<<eno;
	          
			  if(eno==e)
              {
              	flag=1;
              	cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Type: "<<type<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
				
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    
			    		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" "<<type<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		            myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		            myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" "<<type<<" ";
		            myfile1<<contact<<endl;
		      	
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("land.txt");
	rename("temp_land.txt","land.txt");	
}

void land::search()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("land.txt",ios::in);
	
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string scity;
		float sarea;
		cout<<"Enter city name"<<"\n";
	    cin>>scity;
	    cout<<"Enter Area";
	    cin>>sarea;
	    
		string str;
		while (getline(myfile, str))
        {
        	  int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          char type[LEN];
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %ld",&eno,owner,city,&area,&price,type,&contact);
	          string new_city=city;
			  if(new_city==scity && area >=sarea )
              {
              	flag=1;
              	
                cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Type: "<<type<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";	
			  }
        
        
	}
	if(flag==0)
        {
        	cout<<"Requirement Cant be satisfied"<<endl;
		}
	myfile.close();
	
}
}


class flat
{
	public:
    int eno;
	string owner;
	string city;
	float area;
	float price;
	long contact;
	struct details{
		int bath;
		int bed;
		int floor;
    };details d;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void search();
	
};flat f;

void flat::getdata(void)
{
	cout<<"Enter entry number"<<"\n";
	cin>>eno;
	cout<<"Enter owner's name"<<"\n";
	cin>>owner;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter area"<<"\n";
	cin>>area;
	cout<<"Enter price"<<"\n";
	cin>>price;
	cout<<"Enter details"<<"\n";
	cout<<"Enter no. of bedrooms"<<"\n";
	cin>>d.bed;
	cout<<"Enter no. of bathrooms"<<"\n";
	cin>>d.bath;
	cout<<"Enter floor"<<"\n";
	cin>>d.floor;	
	cout<<"Enter contact number"<<"\n";
	cin>>contact;			
}

void flat::display(void)
{
	cout<<"Owner: "<<owner<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Area: "<<area<<"\n";
	cout<<"Price: "<<price<<"\n";
	cout<<"Details: "<<"\n"<<"\n";
	cout<<"No.of bedrooms: "<<d.bed<<"\n";
	cout<<"No.of bathrooms: "<<d.bath<<"\n";
	cout<<"Floor"<<d.floor<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void flat::insert()
{
	
	char buff[MAX];
	fstream myfile;
	myfile.open("flat.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{		
		//myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;

		myfile<<eno<<" "<<owner<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		myfile<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		myfile<<d.bath<<" "<<d.bed<<" "<<d.floor<<" ";
		myfile<<contact<<endl;	
	}
	myfile.close();
}

void flat::record_remove()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("flat.txt",ios::in);
	myfile1.open("temp_flat.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the entry you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          int bath;
	          int bed;
	          int floor;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %d %d %d %ld",&eno,owner,city,&area,&price,&bath,&bed,&floor,&contact);
	          //cout<<eno;
	          
			  if(eno==e)
              {
              	flag=1;
                cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Details: "<<"\n";
	            cout<<"No.of bedrooms: "<<bed<<"\n";
	            cout<<"No.of bathrooms: "<<bath<<"\n";
	            cout<<"Floor"<<floor<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
                
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		                myfile1<<d.bath<<" "<<d.bed<<" "<<d.floor<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		                myfile1<<d.bath<<" "<<d.bed<<" "<<d.floor<<" ";
		                myfile1<<contact<<endl;
		      	
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("flat.txt");
	rename("temp_flat.txt","flat.txt");	
}

void flat::search()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("flat.txt",ios::in);
	
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string scity;
		float sarea;
		cout<<"Enter city name"<<"\n";
	    cin>>scity;
	    cout<<"Enter Area";
	    cin>>sarea;
	    
		string str;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          char type[LEN];
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %ld",&eno,owner,city,&area,&price,type,&contact);
	          string new_city=city;
			  if(new_city==scity && area >=sarea )
              {
              	flag=1;
                cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Details: "<<"\n"<<"\n";
	            cout<<"No.of bedrooms: "<<d.bed<<"\n";
	            cout<<"No.of bathrooms: "<<d.bath<<"\n";
	            cout<<"Floor"<<d.floor<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";				
			  }
        
        
	}
	if(flag==0)
        {
        	cout<<"Requirement Cant be satisfied"<<endl;
		}
	myfile.close();
	
}
}


class house
{
	public:
    int eno;
	string owner;
	string city;
	float area;
	float price;
	long contact;
	struct details
	{
		int bath;
		int bed;
	};details d;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void search();
};house h;

void house::getdata(void)
{
	cout<<"Enter entry number"<<"\n";
	cin>>eno;
	cout<<"Enter owner's name"<<"\n";
	cin>>owner;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter area"<<"\n";
	cin>>area;
	cout<<"Enter price"<<"\n";
	cin>>price;
	cout<<"Enter details"<<"\n";
	cout<<"Enter no. of bedrooms"<<"\n";
	cin>>d.bed;
	cout<<"Enter no. of bathrooms"<<"\n";
	cin>>d.bath;	
	cout<<"Enter contact number"<<"\n";
	cin>>contact;			
}

void house::display(void)
{
	cout<<"Owner: "<<owner<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Area: "<<area<<"\n";
	cout<<"Price: "<<price<<"\n";
	cout<<"Details: "<<"\n";
	cout<<"No.of bedrooms: "<<d.bed<<"\n";
	cout<<"No.of bathrooms: "<<d.bath<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void house::insert()
{
	
	char buff[MAX];
	fstream myfile;
	myfile.open("house.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{		
		//myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;

		myfile<<eno<<" "<<owner<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		myfile<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		myfile<<d.bath<<" "<<d.bed<<" ";
		myfile<<contact<<endl;	
		
	}
	myfile.close();
    } 

void house::record_remove()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("house.txt",ios::in);
	myfile1.open("temp_house.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the entry you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          int bath;
	          int bed;
	          int floor;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %d %d %ld",&eno,owner,city,&area,&price,&bath,&bed,&contact);
	          //cout<<eno;
	          
			  if(eno==e)
              {
              	flag=1;
                cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Details: "<<"\n";
	            cout<<"No.of bedrooms: "<<bed<<"\n";
	            cout<<"No.of bathrooms: "<<bath<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
                
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		                myfile1<<d.bath<<" "<<d.bed<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		    myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		                myfile1<<d.bath<<" "<<d.bed<<" ";
		                myfile1<<contact<<endl;
		      	
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("house.txt");
	rename("temp_house.txt","house.txt");	
}

void house::search()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("house.txt",ios::in);
	
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string scity;
		float sarea;
		cout<<"Enter city name"<<"\n";
	    cin>>scity;
	    cout<<"Enter Area";
	    cin>>sarea;
	    
		string str;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          char type[LEN];
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %ld",&eno,owner,city,&area,&price,type,&contact);
	          string new_city=city;
			  if(new_city==scity && area >=sarea )
              {
              	flag=1;
                	cout<<"Owner: "<<owner<<"\n";
	                cout<<"City: "<<city<<"\n";
	                cout<<"Area: "<<area<<"\n";
	                cout<<"Price: "<<price<<"\n";
	                cout<<"Details: "<<"\n";
	                cout<<"No.of bedrooms"<<d.bed<<"\n";
	                cout<<"No.of bathrooms"<<d.bath<<"\n";
	                cout<<"Contact number: "<<contact<<"\n";	
			  }
        
        
	}
	if(flag==0)
        {
        	cout<<"Requirement Cant be satisfied"<<endl;
		}
	myfile.close();
	
}
}


class shop
{
	public:
    int eno;
	string owner;
	string city;
	float area;
	float price;
	long contact;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void search();
};shop s;

void shop::getdata(void)
{
	cout<<"Enter entry number"<<"\n";
	cin>>eno;
	cout<<"Enter owner's name"<<"\n";
	cin>>owner;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter area"<<"\n";
	cin>>area;
	cout<<"Enter price"<<"\n";
	cin>>price;
	cout<<"Enter contact number"<<"\n";
	cin>>contact;				
}

void shop::display(void)
{
	cout<<"Owner: "<<owner<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Area: "<<area<<"\n";
	cout<<"Price: "<<price<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void shop::insert()
{
	char buff[MAX];
	fstream myfile;
	myfile.open("shop.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{
	    //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;

		myfile<<eno<<" "<<owner<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		myfile<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		myfile<<contact<<endl;
		
	}
	myfile.close();
}

void shop::record_remove()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("shop.txt",ios::in);
	myfile1.open("temp_shop.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the entry you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %ld",&eno,owner,city,&area,&price,&contact);
	          //cout<<eno;
	          
			  if(eno==e)
              {
              	flag=1;
              	
                cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		            myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		            myfile1<<fixed<<setw(12)<<setprecision(2)<<price<<" ";
		            myfile1<<contact<<endl;
		      	
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("shop.txt");
	rename("temp_shop.txt","shop.txt");	
}

void shop::search()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("shop.txt",ios::in);
	
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string scity;
		float sarea;
		cout<<"Enter city name"<<"\n";
	    cin>>scity;
	    cout<<"Enter Area";
	    cin>>sarea;
	    
		string str;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          char type[LEN];
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %ld",&eno,owner,city,&area,&price,type,&contact);
	          string new_city=city;
			  if(new_city==scity && area >=sarea )
              {
              	flag=1;
              	cout<<"Owner: "<<owner<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Price: "<<price<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
			  }
        
        
	}
	if(flag==0)
        {
        	cout<<"Requirement Cant be satisfied"<<endl;
		}
	myfile.close();
	
}
}


class rental
{
	public:
    int eno;
	string owner;
	string city;
	float area;
	float rent;
	long contact;
	struct details
	{
		int bath;
		int bed;
		int floor;
	};details d;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void search();
};rental r;


void rental::getdata(void)
{
	cout<<"Enter entry number"<<"\n";
	cin>>eno;
	cout<<"Enter owner's name"<<"\n";
	cin>>owner;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter area"<<"\n";
	cin>>area;
	cout<<"Enter rent"<<"\n";
	cin>>rent;
	cout<<"Enter details"<<"\n";
	cout<<"Enter no. of bedrooms"<<"\n";
	cin>>d.bed;
	cout<<"Enter no. of bathrooms"<<"\n";
	cin>>d.bath;
	cout<<"Enter floor"<<"\n";
	cin>>d.floor;	
	cout<<"Enter contact number"<<"\n";
	cin>>contact;			
}


void rental::display(void)
{
	cout<<"Owner: "<<owner<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Area: "<<area<<"\n";
	cout<<"Rent: "<<rent<<"\n";
	cout<<"Details: "<<"\n";
	cout<<"No.of bedrooms"<<d.bed<<"\n";
	cout<<"No.of bathrooms"<<d.bath<<"\n";
	cout<<"Floor"<<d.floor<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void rental::insert()
{
	
	char buff[MAX];
	fstream myfile;
	myfile.open("rent.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{		
		//myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;

		myfile<<eno<<" "<<owner<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		myfile<<fixed<<setw(12)<<setprecision(2)<<rent<<" ";
		myfile<<d.bath<<" "<<d.bed<<" "<<d.floor<<" ";
		myfile<<contact<<endl;	
	}
	myfile.close();
}

void rental::record_remove()
{
	
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("rent.txt",ios::in);
	myfile1.open("temp_rent.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the entry you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	 int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double rent;
	          long contact;
	          int bath;
	          int bed;
	          int floor;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %d %d %d %ld",&eno,owner,city,&area,&rent,&bath,&bed,&floor,&contact);
	          //cout<<eno;
	          
			  if(eno==e)
              {
              	flag=1;
                	cout<<"Owner: "<<owner<<"\n";
	                cout<<"City: "<<city<<"\n";
	                cout<<"Area: "<<area<<"\n";
	                cout<<"Rent: "<<rent<<"\n";
	                cout<<"Details: "<<"\n";
	                cout<<"No.of bedrooms"<<bed<<"\n";
	                cout<<"No.of bathrooms"<<bath<<"\n";
	                cout<<"Floor"<<floor<<"\n";
	                cout<<"Contact number: "<<contact<<"\n";
                
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<rent<<" ";
		                myfile1<<d.bath<<" "<<d.bed<<" "<<d.floor<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		myfile1<<eno<<" "<<owner<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<rent<<" ";
		                myfile1<<d.bath<<" "<<d.bed<<" "<<d.floor<<" ";
		                myfile1<<contact<<endl;
		      	
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("rent.txt");
	rename("temp_rent.txt","rent.txt");	
}

void rental::search()
{
	
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("rent.txt",ios::in);
	
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string scity;
		float sarea;
		cout<<"Enter city name"<<"\n";
	    cin>>scity;
	    cout<<"Enter Area";
	    cin>>sarea;
	    
		string str;
		while (getline(myfile, str))
        {
        	  int eno;	
	          char owner[LEN];
	          char city[LEN];
	          float area;
	          double price;
	          long contact;
	          char type[LEN];
	          //myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
	          sscanf(str.c_str(),"%d %s %s %f %lf %s %ld",&eno,owner,city,&area,&price,type,&contact);
	          string new_city=city;
			  if(new_city==scity && area >=sarea )
              {
              	flag=1;
              		cout<<"Owner: "<<owner<<"\n";
	                cout<<"City: "<<city<<"\n";
	                cout<<"Area: "<<area<<"\n";
	                cout<<"Rent: "<<rent<<"\n";
	                cout<<"Details: "<<"\n";
	                cout<<"No.of bedrooms"<<d.bed<<"\n";
	                cout<<"No.of bathrooms"<<d.bath<<"\n";
	                cout<<"Floor"<<d.floor<<"\n";
	                cout<<"Contact number: "<<contact<<"\n";
			  }
        }
	if(flag==0)
        {
        	cout<<"Requirement Cant be satisfied"<<endl;
		}
	myfile.close();
}
}


void search()
{
	char found='n';
	cout<<"IF YOU WANT TO SEARCH LAND PRESS 1"<<"\n";
	cout<<"IF YOU WANT TO SEARCH FLAT PRESS 2"<<"\n";
	cout<<"IF YOU WANT TO SEARCH HOUSE PRESS 3"<<"\n";
	cout<<"IF YOU WANT TO SEARCH SHOP PRESS 4"<<"\n";
	cout<<"IF YOU WANT TO SEARCH RENTAL PRESS 5"<<"\n";
	int ch;
	int c;
	cin>>ch;
	switch(ch)
	{
		case 1:
	       l.search();
	       break;
		case 2:
		   f.search();
		   break;	
		case 3:
		   h.search();
		   break;
		case 4:
		   s.search();	
		   break;
		case 5:
           r.search();		
		   break;
        default:
           cout<<"Wrong choice";
	}

}


void administration()
{
    int ch;
    int flag = 1;
    while(flag)
    {
    cout<<"\n\n";	
	cout<<"**********************************************"<<"\n";
    cout<<"* IF YOU WANT TO DEAL WITH LAND PRESS      1 *"<<"\n";
	cout<<"* IF YOU WANT TO DEAL WITH FLAT PRESS      2 *"<<"\n";
	cout<<"* IF YOU WANT TO DEAL WITH HOUSE PRESS     3 *"<<"\n";
	cout<<"* IF YOU WANT TO DEAL WITH SHOP PRESS      4 *"<<"\n";
	cout<<"* IF YOU WANT TO DEAL WITH RENTAL PRESS    5 *"<<"\n";
	cout<<"* IF YOU WANT TO SEARCH FOR PROPERTY PRESS 6 *"<<"\n";
	cout<<"* IF YOU WANT TO GO TO PREVIOUS MENU PRESS 7 *"<<"\n";
	cout<<"**********************************************"<<"\n";
	cout<<"Enter your Choice: ";
	cin>>ch;
	
	switch(ch)
	{
	char c;	
	case 1:
	cout<<"IF YOU WANT TO INSERT DATA PRESS i"<<"\n";
	cout<<"IF YOU WANT TO DELETE DATA PRESS d"<<"\n";
	cin>>c;
	
    if(c=='i')
	{
	  l.getdata();
	  l.display();
	  l.insert();	
	} 
	else if(c=='d')
    {
    l.record_remove();
    }
	else{
	cout<<"Wrong choice,Try again";
    }  
	break;
	
	case 2:
	cout<<"IF YOU WANT TO INSERT DATA PRESS i"<<"\n";
	cout<<"IF YOU WANT TO DELETE DATA PRESS d"<<"\n";
	cin>>c;
	if(c=='i')
	{
	  f.getdata();
	  f.display();
	  f.insert();	
	} 
	else if(c=='d')
    {
    f.record_remove();
    }
	else{
	
	cout<<"Wrong choice,choose again";
	cin>>ch;
	}
    break;

    case 3:
	cout<<"IF YOU WANT TO INSERT DATA PRESS i"<<"\n";
	cout<<"IF YOU WANT TO DELETE DATA PRESS d"<<"\n";
	cin>>c;
	if(c=='i')
	{
	  h.getdata();
	  h.display();
	  h.insert();	
	} 
	else if(c=='d')
    {
    h.record_remove();
    }
	else{
	cout<<"Wrong choice,Try again";
    }
    break;
    case 4:
	cout<<"IF YOU WANT TO INSERT DATA PRESS i"<<"\n";
	cout<<"IF YOU WANT TO DELETE DATA PRESS d"<<"\n";
	cin>>c;
	if(c=='i')
	{
	  s.getdata();
	  s.display();
	  s.insert();	
	} 
	else if(c=='d')
    {
    s.record_remove();
    }
	
	else{
	cout<<"Wrong choice,try again";
    }
    break;
    case 5:
    cout<<"IF YOU WANT TO INSERT DATA PRESS i"<<"\n";
	cout<<"IF YOU WANT TO DELETE DATA PRESS d"<<"\n";
	cin>>c;
    if(c=='i')
	{
	  r.getdata();
	  r.display();
	  r.insert();	
	} 
	else if(c=='d')
    {
    r.record_remove();
    }
	else{
	cout<<"Wrong choice,Try again";
	}
	break;
    case 6:
	search();
break;

case 7:
	flag=0;
	break;
}

}
}


class customer
{
	public:
	int id;	
	string name;
	string address;
	string city;
	string type;
	long contact;
	float area;
	float budget;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void show_file();
};customer c;

void customer::getdata(void)
{
	cout<<"Enter customer record Id"<<"\n";
	cin>>id;
	int x;
	cout<<"Enter type of customer"<<"\n";
	cout<<"If customer is buyer press 1.If customer is seller press 2."<<"\n";
	cin>>x;
	if(x==1)
	{
		type="Buyer";
	}
	else if(x==2)
	{
		type="Seller";
	}
	cout<<"Enter customer's name"<<"\n";
	cin>>name;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter address"<<"\n";
	cin>>address;
	cout<<"Enter requirements"<<"\n";
	cout<<"Enter area"<<"\n";
	cin>>area;
	cout<<"Enter budget"<<"\n";
	cin>>budget;	
	cout<<"Enter contact number"<<"\n";
	cin>>contact;			
}

void customer::display(void)
{
	cout<<"Name: "<<name<<"\n";
	cout<<"Type: "<<type<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Area: "<<area<<"\n";
	cout<<"Budget: "<<budget<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void customer::insert()
{
	fstream myfile;
	myfile.open("customer.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{		
		//myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
        
		myfile<<id<<" "<<type<<" "<<name<<" "<<address<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		myfile<<fixed<<setw(12)<<setprecision(2)<<budget<<" ";
		myfile<<contact<<endl;	
	}
	myfile.close();
}

void customer::record_remove()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("customer.txt",ios::in);
	myfile1.open("temp_customer.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the id you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	  int id;	
	          char name[LEN];
	          char address[LEN];
	          char city[LEN];
	          float area;
	          double budget;
	          long contact;
	          int type;
	          sscanf(str.c_str(),"%d %d %s %s %s %f %lf %ld",&id,&type,name,address,city,&area,&budget,&contact);
	          //cout<<eno;
	          
			  if(id==e)
              {
              	flag=1;
              	cout<<"Name: "<<name<<"\n";
	            cout<<"Type: "<<type<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Area: "<<area<<"\n";
	            cout<<"Budget: "<<budget<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
                
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    		myfile1<<id<<" "<<type<<" "<<name<<" "<<address<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<budget<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		myfile1<<id<<" "<<type<<" "<<name<<" "<<address<<" "<<city<<" ";
		            myfile1<<fixed<<setw(10)<<setprecision(2)<<area<<" ";
		            myfile1<<fixed<<setw(12)<<setprecision(2)<<budget<<" ";
		            myfile1<<contact<<endl;
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("customer.txt");
	rename("temp_customer.txt","customer.txt");	
}

void customer::show_file()
{
	fstream myfile;
	myfile.open("customer.txt",ios::in);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string str;
		while (getline(myfile, str))
        {
	
	       if(str.size() > 0)
		    cout<<str<<endl;
        }
	}
	myfile.close();
}

class dealer
{
	public:
	int id;	
	string name;
	string address;
	string city;
	long contact;
	float salary;
	int no_of_dealings;
	void getdata(void);
	void display(void);
	void insert();
	void record_remove();
	void show_file();
};dealer d;

void dealer::getdata(void)
{
	cout<<"Enter dealer record Id";
	cin>>id;
	cout<<"Enter dealer's name"<<"\n";
	cin>>name;
    cout<<"Enter city"<<"\n";
	cin>>city;
	cout<<"Enter address"<<"\n";
	cin>>address;
	cout<<"Enter salary"<<"\n";
	cin>>salary;
	cout<<"Enter number of dealings"<<"\n";
	cin>>no_of_dealings;	
	cout<<"Enter contact number"<<"\n";
	cin>>contact;			
}

void dealer::display(void)
{
	cout<<"Name: "<<name<<"\n";
	cout<<"City: "<<city<<"\n";
	cout<<"Salary: "<<salary<<"\n";
	cout<<"Number of dealings: "<<no_of_dealings<<"\n";
	cout<<"Contact number: "<<contact<<"\n";
}

void dealer::insert()
{
	fstream myfile;
	myfile.open("dealer.txt",ios::app);
	if(!myfile)
	{
		cout<<"Unable to create/open file";
	}
	else
	{		
		//myfile<<eno<<" "<<owner<<" "<<city<<" "<<area<<" "<<price<<" "<<type<<" "<<contact<<endl;
        
		myfile<<id<<" "<<name<<" "<<address<<" "<<city<<" ";
		myfile<<fixed<<setw(10)<<setprecision(2)<<" "<<no_of_dealings;
		myfile<<fixed<<setw(12)<<setprecision(2)<<salary<<" ";
		myfile<<contact<<endl;	
	}
	myfile.close();
}

void dealer::record_remove()
{
	int flag = 0;
	fstream myfile;
	fstream myfile1;
	myfile.open("dealer.txt",ios::in);
	myfile1.open("temp_dealer.txt",ios::out);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else if(!myfile1)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		int e;
		cout<<"Enter the id you want to delete"<<"\n";
	    cin>>e;
		string str;
		char confirm;
		while (getline(myfile, str))
        {
        	  int id;	
	          char name[LEN];
	          char address[LEN];
	          char city[LEN];
	          double salary;
	          long contact;
	          int no_of_dealings;
	          sscanf(str.c_str(),"%d %d %s %s %s %f %lf %ld",&id,&name,address,city,&no_of_dealings,&salary,&contact);
	          //cout<<eno;
	          
			  if(id==e)
              {
              	flag=1;
              	cout<<"Name: "<<name<<"\n";
	            cout<<"City: "<<city<<"\n";
	            cout<<"Number of dealings: "<<no_of_dealings<<"\n";
	            cout<<"Salary: "<<salary<<"\n";
	            cout<<"Contact number: "<<contact<<"\n";
                
				cout<<"Are you sure you want to delete data? (y/n)"<<"\n";
			    cin>>confirm;
			    if(confirm=='n' || confirm =='N')
			    		myfile1<<id<<" "<<name<<" "<<address<<" "<<city<<" ";
		                myfile1<<fixed<<setw(10)<<setprecision(2)<<no_of_dealings<<" ";
		                myfile1<<fixed<<setw(12)<<setprecision(2)<<salary<<" ";
		                myfile1<<contact<<endl;
			    
			  }
		      else
		      {
		      		myfile1<<id<<" "<<name<<" "<<address<<" "<<city<<" ";
		            myfile1<<fixed<<setw(10)<<setprecision(2)<<no_of_dealings<<" ";
		            myfile1<<fixed<<setw(12)<<setprecision(2)<<salary<<" ";
		            myfile1<<contact<<endl;
			  }
        }
        
        if(flag==0)
        {
        	cout<<"Record not found"<<endl;
		}
        
	}
	myfile.close();
	myfile1.close();
	remove("dealer.txt");
	rename("temp_dealer.txt","dealer.txt");	
}

void dealer::show_file()
{
	fstream myfile;
	myfile.open("dealer.txt",ios::in);
	if(!myfile)
	{
		cout<<"File dosn't exist. Record not found Create Some record";
	}
	else
	{
		string str;
		while (getline(myfile, str))
        {
	
	       if(str.size() > 0)
		    cout<<str<<endl;
        }
	}
	myfile.close();
}


int main()
{
	int ch;
	int flag=1;
	while(flag)
	{
	cout<<"\n\n";	
	cout<<"**********************************************"<<"\n";
    cout<<"*          PROPERTY MANAGEMENT        1 *"<<"\n";
	cout<<"*          CUSTOMER MANAGEMENT        2 *"<<"\n";
	cout<<"*           DEALER MANAGEMENT         3 *"<<"\n";
	cout<<"*                 EXIT                4 *"<<"\n";
	cout<<"**********************************************"<<"\n";
	cout<<"Enter your Choice: ";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
		administration();
		break;
		case 2:
		int x;
		cout<<"Insert customer Record   1"<<"\n";
		cout<<"Remove Customer Record   2"<<"\n";
		cout<<"Display all record       3"<<"\n";
        cin>>x;
		if(x==1)
        {
		c.getdata();
		c.insert();
		c.display();
		}
		else if(x==2)
		{
			c.record_remove();
		}
		else if(x==3)
		{
			c.show_file();
		}
		break;
		
		case 3:
		cout<<"Insert dealer Record   1"<<"\n";
		cout<<"Remove dealer Record   2"<<"\n";
		cout<<"Display all record     3"<<"\n";
        cin>>x;
		if(x==1)
        {
		d.getdata();
		d.insert();
		d.display();
		}
		else if(x==2)
		{
			d.record_remove();
		}
		else if(x==3)
		{
			d.show_file();
		}
		break;
	
	    case 4:
	    	flag=0;
	    break;	 
		
		default:
		cout<<"Wrong choice";	
	}
}
}

 

	

