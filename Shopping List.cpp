#include <iostream> 
#include <vector> 
using namespace std;
class Shopping_List_App
{
	private:
		vector<string> my_list;
	public:
		bool search_item(string item)
		{
			for(string i: my_list)
			{
				if(i==item)
					return  true;
		    }
		    return false;
		}
		
		void add_item(string item)
		{
			if(search_item(item)==false)
			{
				my_list.emplace_back(item);
		        cout<<"\n"<<item<<" added in list.";
			}
			else
				cout<<"\n"<<item<<" already in list";
		}
       void delete_item(string item)
		{
			if(search_item(item)==false)
			{
		        cout<<"\n"<<item<<" not in list";
			}
			else
			{
				for(int i=0;i<my_list.size();i++)
				{
				  if(my_list[i]==item)
				  {
					my_list.erase(my_list.begin()+i);
					cout<<"\n"<<item<<" deleted from list";
				  }
			    }    
			}
		}
	    void display_list()
		{
		  if(!my_list.empty())
		   {
		   	cout<<"\nLIST HAS\n";
		   	cout<<"---------------------------------";
				for(int i=0;i<my_list.size();i++)
				{
					cout<<"\n"<<(i+1)<<". "<<my_list[i]<<endl;
				  }
			    }    
			}
		};		
		    
		
int main() {
Shopping_List_App app;
    int choice;
    string item_name;


    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Add an item" << endl;
        cout << "2. Delete an item" << endl;
        cout << "3. View list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume the newline character


        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                getline(cin, item_name);
                app.add_item(item_name);
                break;
            case 2:
                cout << "Enter item to delete: ";
                getline(cin, item_name);
                app.delete_item(item_name);
                break;
            case 3:
                app.display_list();
                break;
            case 0:
                cout << "\nExiting the app. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 0);


    return 0;
}
