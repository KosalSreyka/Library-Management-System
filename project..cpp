                                   
								    // Project :library management
                                          
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
 using namespace std;                 
  class stock
  {
  	 protected :
  	 	  int id;
  	 	  char book_name[100];
  	 	  int Qty;
  	 	  float total,price;
  	 	  char date_time[30];
		  char str[200];
  	 public :
  	 	int get_id()
  	 	{
  	 		return id;
		}
		void input()
		{
				
				cout<<"enter ID :";cin>>id;cin.ignore();
				cout<<"enter Name of Book :";cin.getline(book_name,100);
				cout<<"enter Qty :";cin>>Qty;
				cout<<"enter price :";cin>>price;
				cout<<"Date_time :";cin.ignore();cin.getline(date_time,30);
				total=price*Qty;
		
			
		}
	void output()
		{
		  cout<<setw(10)<<id<<setw(13)<<book_name<<setw(10)<<Qty<<setw(10)<<price<<setw(10)<<total<<setw(15)<<date_time;
		}
  };
 
  class staff :public stock
  {
  	 protected :
  	 	char name[20];
  	 	char sex;
  	 	char date_of_birth[20];
  	 	char position[20];
  	 	float salary;
  	 public :
  	 	void input()
  	 	   {
				cout<<"enter ID :";cin>>id;cin.ignore();
				cout<<"enter Name :";cin.getline(name,100);
				cout<<"enter Sex :";cin>>sex;
				cout<<"enter date of birth :";cin>>date_of_birth;
				cout<<"enter position :";cin.ignore();cin.getline(position,20);	
				cout<<"enter salary :";cin>>salary;
			}	 		
		
		void output()
		   {
			
			   cout<<setw(10)<<id<<setw(13)<<name<<setw(10)<<sex<<setw(10)<<date_of_birth<<setw(10)<<position<<setw(15)<<salary<<endl;
		   }
	
  };
  class sell:public stock
  {
  	 private :
 	 	char phone[20];
 	 
  	 public :
  	 	void input()
 	 	{
 	 		stock::input();
  	 		cout<<"Phone :";cin>>phone;
		}
		void output()
		{
			stock::output();
			cout<<setw(10)<<phone<<endl;
		}
  };
 void option()
  {
  	cout<<"   ============================="<<endl;
  	cout<<"\t1.Stock "<<endl;
  	cout<<"\t2.Staff "<<endl;
  	cout<<"\t3.Sell  "<<endl;
  	cout<<"\t4.Exit..."<<endl;
  	cout<<"   ============================="<<endl;
  }
  void menu()
  {
  	cout<<"   ============================="<<endl;
  	cout<<"   |||||||||||| Menu||||||||||||"<<endl;
	cout<<"   ============================="<<endl;
  	cout<<"\t1.Write Data into file"<<endl;
  	cout<<"\t2.Read Data from file"<<endl;
  	cout<<"\t3.Search Data in file"<<endl;
  	cout<<"\t4.Update Date in file"<<endl;
  	cout<<"\t5.Delete Data in file"<<endl;
  	cout<<"\t6.Insert Data in file"<<endl;
  	cout<<"\t7.Sort Data in file"<<endl;
  	cout<<"\t0.Exit..."<<endl;
  
  }
    void stock_header()
   {
  	  	cout<<setw(10)<<"ID"<<setw(13)<<"Book_Name"<<setw(10)<<"Qty"<<setw(10)<<"Price"<<setw(10)<<"Total"<<setw(15)<<"Date_time"<<endl;
		cout<<"-----------------------------------------------------------------------\n";
   }
  void sell_header()
   {
  	    cout<<setw(10)<<"ID"<<setw(13)<<"Book_Name"<<setw(10)<<"Qty"<<setw(10)<<"Price"<<setw(10)<<"Total"<<setw(15)<<"Date_time"<<setw(10)<<"Phone"<<endl;
  	    cout<<"------------------------------------------------------------------------------------\n";
   }
  void staff_header()
   {
  	    cout<<setw(10)<<"ID"<<setw(13)<<"Name"<<setw(10)<<"Sex"<<setw(10)<<"DOB"<<setw(10)<<"Position"<<setw(15)<<"Salary"<<endl;
		cout<<"-----------------------------------------------------------------------\n";
   }
  
   int main()
   {
   	 const char *filename="Book.bin";
   	 const char *newfilename="temp.bin";
   	 int op,n,ch,i;
   	  stock obj;
   	  staff obj1;
   	  sell obj2;
   	  do
		{
		    option();
		 	cout<<"enter option :";cin>>op;
		 	
		 	if(op==1)
		 	{
		 		cout<<"\t>>>>>>>>Stock<<<<<<<<"<<endl;
		 		do
				 {
				 	   menu();
		 		       cout<<"Choose ... :";cin>>ch;
		 		    switch(ch)
		 		     {
		 			   case 1:
		 				  {
		 				  	fstream file;
	                        file.open(filename,ios::out|ios::binary);
			                 if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
		 					cout<<"enter numbers of book :";cin>>n;
		 					cout<<"Enter Data of Book into file\n";
		 					for( i=0;i<n;i++)
		 					{
		 						obj.input();
								file.write((char *)&obj,sizeof obj);
							}
							file.close();
						  }break;
					    case 2:
					     {
						    fstream file;
			                file.open(filename,ios::in|ios::binary);
			                if(file.fail())
			                    {
			                    	cout<<"file not found"<<endl;
				                    exit(0);
			                    }
								stock_header();
			                while(file.read((char*)&obj,sizeof obj))
					     	{
					     		obj.output();
					     		cout<<endl;
							}
						   
					     }break;
					    case 3:
					     {
					    	fstream file;
  	                        file.open(filename,ios::in|ios::binary);
  	                        int sid,f=0;
  	                        cout<<"enter ID for search :";cin>>sid;
  	                        while(file.read((char*)&obj,sizeof obj))
  	                        {
  		                        if(obj.get_id()==sid)
  		                            {
  		                            	stock_header();
  			                            obj.output();
  			                            cout<<endl;
  			                            f=1;
  			                            break;
		                            }
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        file.close();
						 }break;
						case 4:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to update :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj,sizeof obj))
  	                        {
  		                        if(obj.get_id()==sid)
  		                            {
  		                               obj.input();
									   filenew.write((char*)&obj,sizeof obj);
									   f=1;
		                            }
		                        else
		                         filenew.write((char*)&obj,sizeof obj);
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                            cout<<"Update Success..."<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
					    case 5:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to Delete :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj,sizeof obj))
  	                        {
  		                        if(obj.get_id()==sid)
  		                            {
									   f=1;
		                            }
		                        else
		                         filenew.write((char*)&obj,sizeof obj);
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                          cout<<"Delete Success"<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
						case 6:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to Insert :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj,sizeof obj))
  	                        {
							   filenew.write((char*)&obj,sizeof obj);
  		                        if(obj.get_id()==sid)
  		                            {
  		                               obj.input();
									   filenew.write((char*)&obj,sizeof obj);
									   f=1;
		                            }            
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                            cout<<"Insert Success..."<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
						case 7:
						 {
						 	fstream file,filenew;
						 	stock temp,array[50];
						 	int f=0;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj,sizeof obj))
  	                        {
  		                         array[f]=obj;
  		                         f++;
	                        }
	                        for(i=0;i<f;i++)
	                         {
	                         	for(int j=i+1;j<f;j++)
	                         	{
	                         	   if(array[i].get_id()<array[j].get_id())	
	                         	     {
	                         	     	temp=array[i];
	                         	     	array[i]=array[j];
	                         	     	array[j]=temp;	                         	     	
									 }
								}
								filenew.write((char*)&array[i],sizeof array[i]);
							 }
							 
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;			
				     }
					 cout<<"press enter key to continue..."<<endl;    
			     }while(getch()&&ch!=0);	
		    }
		    else if(op==2)
		 	{
		 		cout<<"\t>>>>>>>>Staff<<<<<<<<"<<endl;
		 		do
				 {
				 	   menu();
		 		       cout<<"Choose ... :";cin>>ch;
		 		    switch(ch)
		 		     {
		 			   case 1:
		 				  {
		 				  	fstream file;
	                        file.open(filename,ios::out|ios::binary);
			                 if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
		 					cout<<"enter numbers of Staff :";cin>>n;
		 					for( i=0;i<n;i++)
		 					{
		 						obj1.input();
								file.write((char *)&obj1,sizeof obj1);
							}
							file.close();
						  }break;
					    case 2:
					     {
						    fstream file;
			                file.open(filename,ios::in|ios::binary);
			                if(file.fail())
			                    {
			                    	cout<<"file not found"<<endl;
				                    exit(0);
			                    }
								staff_header();
			                while(file.read((char*)&obj1,sizeof obj1))
					     	{
					     		obj1.output();
					     		cout<<endl;
							}
						   
					     }break;
					    case 3:
					     {
					    	fstream file;
  	                        file.open(filename,ios::in|ios::binary);
  	                        int sid,f=0;
  	                        cout<<"enter ID for search :";cin>>sid;
  	                        while(file.read((char*)&obj1,sizeof obj1))
  	                        {
  		                        if(obj1.get_id()==sid)
  		                            {
  		                            	staff_header();
  			                            obj1.output();
  			                            f=1;
  			                            break;
		                            }
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        file.close();
						 }break;
						case 4:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to update :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj1,sizeof obj1))
  	                        {
  		                        if(obj1.get_id()==sid)
  		                            {
  		                               obj1.input();
									   filenew.write((char*)&obj1,sizeof obj1);
									   f=1;
		                            }
		                        else
		                         filenew.write((char*)&obj1,sizeof obj1);
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                            cout<<"Update Success..."<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
					    case 5:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to Delete :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj1,sizeof obj1))
  	                        {
  		                        if(obj1.get_id()==sid)
  		                            {
									   f=1;
		                            }
		                        else
		                         filenew.write((char*)&obj1,sizeof obj1);
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                          cout<<"Delete Success"<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
						case 6:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to Insert :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj1,sizeof obj1))
  	                        {
							   filenew.write((char*)&obj1,sizeof obj1);
  		                        if(obj1.get_id()==sid)
  		                            {
  		                               obj1.input();
									   filenew.write((char*)&obj1,sizeof obj1);
									   f=1;
		                            }                        
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                            cout<<"Insert Success..."<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
						case 7:
						 {
						 	fstream file,filenew;
						 	staff temp,array[50];
						 	int f=0;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj1,sizeof obj1))
  	                        {
  		                         array[f]=obj1;
  		                         f++;
	                        }
	                        for(i=0;i<f;i++)
	                         {
	                         	for(int j=i+1;j<f;j++)
	                         	{
	                         	   if(array[i].get_id()<array[j].get_id())	
	                         	     {
	                         	     	temp=array[i];
	                         	     	array[i]=array[j];
	                         	     	array[j]=temp;	                         	     	
									 }
								}
								filenew.write((char*)&array[i],sizeof array[i]);
							 }
							 
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;	
				     }
					 cout<<"press enter key to continue..."<<endl;    
			     }while(getch()&&ch!=0);		 		
		    }
		    else if(op==3)
		 	{
		 		cout<<"\t>>>>>>>>Sell<<<<<<<<"<<endl;
		 		do
				 {
				 	   menu();
		 		       cout<<"Choose ... :";cin>>ch;
		 		    switch(ch)
		 		     {
		 			   case 1:
		 				  {
		 				  	fstream file;
	                        file.open(filename,ios::out|ios::binary);
			                 if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
		 					cout<<"enter numbers of Sell :";cin>>n;
		 					for( i=0;i<n;i++)
		 					{
		 						obj2.input();
								file.write((char *)&obj2,sizeof obj2);
							}
							file.close();
						  }break;
					    case 2:
					     {
						    fstream file;
			                file.open(filename,ios::in|ios::binary);
			                if(file.fail())
			                    {
			                    	cout<<"file not found"<<endl;
				                    exit(0);
			                    }
								sell_header();
			                while(file.read((char*)&obj2,sizeof obj2))
					     	{
					     		obj2.output();
							}
						   
					     }break;
					    case 3:
					     {
					    	fstream file;
  	                        file.open(filename,ios::in|ios::binary);
  	                        int sid,f=0;
  	                        cout<<"enter ID for search :";cin>>sid;
  	                        while(file.read((char*)&obj2,sizeof obj2))
  	                        {
  		                        if(obj2.get_id()==sid)
  		                            {
  		                            	sell_header();
  			                            obj2.output();
  			                            f=1;
  			                            break;
		                            }
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        file.close();
						 }break;
						case 4:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to update :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj2,sizeof obj2))
  	                        {
  		                        if(obj2.get_id()==sid)
  		                            {
  		                               obj2.input();
									   filenew.write((char*)&obj2,sizeof obj2);
									   f=1;
		                            }
		                        else
		                         filenew.write((char*)&obj2,sizeof obj2);
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                            cout<<"Update Success..."<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
					    case 5:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to Delete :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj2,sizeof obj2))
  	                        {
  		                        if(obj2.get_id()==sid)
  		                            {
									   f=1;
		                            }
		                        else
		                         filenew.write((char*)&obj2,sizeof obj2);
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                          cout<<"Delete Success"<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
						case 6:
						 {
						 	fstream file,filenew;
						 	int sid,f=0;
  	                        cout<<"enter ID that you want to Insert :";cin>>sid;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj2,sizeof obj2))
  	                        {
							   filenew.write((char*)&obj2,sizeof obj2);
  		                        if(obj2.get_id()==sid)
  		                            {
  		                               obj2.input();
									   filenew.write((char*)&obj2,sizeof obj2);
									   f=1;
		                            }		                         
	                        }
	                        if(f==0)
	                            cout<<"ID not found"<<endl;
	                        else
	                            cout<<"Insert Success..."<<endl;
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
						case 7:
						 {
						 	fstream file,filenew;
						 	sell temp,array[50];
						 	int f=0;
						 	file.open(filename,ios::in|ios::binary);
  	                        filenew.open(newfilename,ios::out|ios::binary);
  	                        if(file.fail())
			                   {
				                   cout<<"Can't Create file"<<endl;
				                    exit(0);
			                   }
  	                          while(file.read((char*)&obj2,sizeof obj2))
  	                        {
  		                         array[f]=obj2;
  		                         f++;
	                        }
	                        for(i=0;i<f;i++)
	                         {
	                         	for(int j=i+1;j<f;j++)
	                         	{
	                         	   if(array[i].get_id()<array[j].get_id())	
	                         	     {
	                         	     	temp=array[i];
	                         	     	array[i]=array[j];
	                         	     	array[j]=temp;	                         	     	
									 }
								}
								filenew.write((char*)&array[i],sizeof array[i]);
							 }
							 
	                        file.close();
	                        filenew.close();
  	                        remove(filename);
	                        rename(newfilename,filename);
						 	
						 }break;
				     }
					 cout<<"press enter key to continue..."<<endl;    
			     }while(getch()&&ch!=0);	
		    }		 	
		}while(getch()&&op!=4);
   	
   	cout<<"\tBye...!!Thanks \3"<<endl;
   }
