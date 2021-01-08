#include <iostream>
#include <cmath>

void promptScript(){
	std::cerr<<"Select your function (1, 2, 3, 4, or 0):"<<std::endl;
	std::cerr<<"1: sin(x)cos(y)"<<std::endl;
	std::cerr<<"2: sin(x)+cos^2(y/2)-x/y"<<std::endl;
	std::cerr<<"3: 1/2 sin(x) + 1/2 cos(y)"<<std::endl;
	std::cerr<<"4: 1/2 sin(x) + xcos(3y)"<<std::endl;
	std::cerr<<"0: Quit"<<std::endl;
}

void graduations(){
	std::cerr<<"How many graduations per axis (level of precision)? "<<std::endl;
}

void typeOfData(){
	std::cerr<<"Bitmap(0) or Values(1)? "<<std::endl;
}

void data(int equation){
	int grads;
	int type;
	double xincrement, yincrement;

	graduations();
        std::cin>>grads;
        double data[grads][grads];
        xincrement = (11)/(double)grads;
        yincrement = (18)/(double)grads;

        for(int i=0; i<grads; i++){
        	double x;
        	x= -4 + (double)((i)*xincrement);
                for(int j=0; j<grads; j++){
                	double  y;
                        double value;
                        y = -12 + (double)((j)*yincrement);
                        if(equation==1){
				data[i][j] = sin(x)*cos(y);
			}
			else if(equation==2){
				data[i][j] = sin(x)+(pow(cos((1/2)*y), 2))-(x/y);	
			}
			else if(equation==3){
				double half = (double)1/(double)2;
				data[i][j] = (half*sin(x))+(half*cos(y));
			}
			else if(equation==4){
				double half = (double)1/(double)2;
				data[i][j] = (half*sin(x))+(x*cos(3*y));
			}
                }
        }
        typeOfData();
        std::cin>>type;
        switch(type){
        	case 0:
                	for(int i=0; i<grads; i++){
                        	for(int j=0; j<grads; j++){
                                	if(data[i][j]>=0){
                                        std::cout<<"O";
                                	}
                                        else if(data[i][j]<0){
                                        	std::cout<<"X";
                                        }
                                }
                                std::cout<<"\n";
                        }
                        break;
               	case 1:
			for(int i=0; i<grads; i++){
				for(int j=0; j<grads; j++){
					std::cout<<data[i][j]<<" ";
                              	}
                                std::cout<<"\n";
                        }
                        break;

               	default:
                       	break;
   	}
}

int main(){
	bool running = true;
	while(running){
		int choice;
		promptScript();
		std::cin>>choice;
		switch(choice){
			case 0:
				running = false;
				break;
			case 1:
				data(1);
				break;
			case 2:
				data(2);
				break;
			case 3:
				data(3);
				break;
			case 4:
				data(4);
				break;
			default:
				break;
		}
		std::cout<<"\n";
	}
	return 0;
}
