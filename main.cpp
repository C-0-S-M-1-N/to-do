#include<bits/stdc++.h>

struct elem{
	std::string name;
	std::string tag = "TODO";
};

std::vector<elem> v;
bool hide_done = 0;

void cls();

void write(){
	cls();
	std::cout<<"TODO:\n";
	std::vector<std::string> ding, dne;
	int a{0}, b{0}, c{0};
	for(int i = 0; i<v.size(); i++){
		if(v[i].tag == "TODO"){
			std::cout<<++a<<"."<<v[i].name<<'\n';
		}else if(v[i].tag == "DOING")ding.push_back(v[i].name);
		else if(v[i].tag == "DONE")dne.push_back(v[i].name);
	}
	std::cout<<"\nDOING:\n";
	for(int i = 0; i<ding.size(); i++){
		std::cout<<++b<<'.'<<ding[i]<<'\n';
	}
	if(hide_done) return;
	std::cout<<"\nDONE:\n";
	for(int i = 0; i<dne.size(); i++) std::cout<<++c<<'.'<<dne[i]<<'\n';
}


int main(int args, char** argv){
	std::ifstream file(argv[1]);
	std::string command;

	while(!file.eof()){
		std::string n, t; file>>n>>t;
		elem e; e.name = n, e.tag = t;
		v.push_back(e);
	}
	file.close();

	while(command != "quit" && command != "q"){
		write();
TOP:
		std::cout<<">"; std::cin>>command;
		if(command == "add" || command == "a"){
			std::string str; std::cin>>str;
			elem e;
			e.name = str, e.tag = "TODO";
			v.push_back(e);
		}else if(command == "remove" || command == "rm"){
			std::string str; std::cin>>str;
			bool er = 0;
			for(int i = 0; i<v.size(); i++) if(v[i].name == str) {v.erase(v.begin()+i); er = 1; break;}
			if(!er) std::cout<<str<<" dose not exist in the curent case, use add "<<str<<" to add it!\n";
		}else if(command == "doing" || command == "g"){
			std::string str; std::cin>>str; bool er = 0;
			for(int i = 0; i<v.size(); i++){
				if(v[i].name == str){v[i].tag = "DOING", er = 1; break;}
			}
			if(!er){
				elem e; e.name = str, e.tag = "DOING"; v.push_back(e);
			} 
		}else if(command == "done" || command == "d"){
			std::string str; std::cin>>str; bool er = 0;
			for(int i = 0; i<v.size(); i++){
				if(v[i].name == str){v[i].tag = "DONE", er = 1; break;}
			}
			if(!er){
				elem e; e.name = str, e.tag = "DONE";
				v.push_back(e);
			}
		}else if(command == "help" || command == "h"){
			std::cout<<"add (a) name -> adds a new element to the list {default as TODO}\n";
			std::cout<<"remove (rm) name -> removes {name} from the list (note that the lable dose not matter)\n";
			std::cout<<"doing (g) name -> moves/adds {name} from any lable to DOING lable\n";
			std::cout<<"done (d) name -> moves/adds {name} from any lable to DONE\n";
			std::cout<<"todo (td) name -> moves/adds {name} from any lable to DONE\n";
			std::cout<<"help (h) -> well if you are here you shoud know wath it dose\n";
			std::cout<<"quit (q) -> exits the progarm and saves the work!\n";
			goto TOP;
		}else if(command == "todo" || command == "td"){
			std::string str; std::cin>>str; bool er = 0;
			for(int i = 0; i<v.size(); i++){
				if(v[i].name == str){v[i].tag = "TODO", er = 1; break;}
			}
			if(!er){
				elem e; e.name = str, e.tag = "TODO";
				v.push_back(e);
			}

		}
	}
	std::ofstream filr(argv[1]);
	for(auto i : v){filr << i.name << " "<<i.tag<<'\n';}
	filr.close();
}


void cls(){
#if _WIN32
	system("cls");
#elif __unix__
	system("clear");
#endif
}
