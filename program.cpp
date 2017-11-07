#include<iostream>
using namespace std;

class cash_dispense{
	cash_dispense *next;
	public:
	cash_dispense(){
		next=NULL;
	}
	
	void set_next(cash_dispense* b){
		
		next=b;
	}
	
	virtual void handle(int &currency_remain){
		next->handle(currency_remain);
	}

    void add(cash_dispense* c){//add object in chain
    
        if(next==NULL){
            next=c;
        }else{
            next->add(c);
        }   
    }
};

class cash_two_thousand:public cash_dispense{
	public:
	
	int two_thousand=0;
	void handle(int &cash){
	  if(cash==2000){
		  cash=0;
		  two_thousand++;
	  }else if(cash>2000){
		  cash=cash-2000;
		  two_thousand++;
		  cash_dispense::handle(cash);
	  }else if(cash<2000){
		   cash_dispense::handle(cash);
	  }
	  
	}
	
	int get_val(){
		return two_thousand;
	}
};


class cash_five_hundred:public cash_dispense{
	public:
	int five_hundred=0;
	void handle(int &cash){
	  if(cash==500){
		  cash=0;
		  five_hundred++;
	  }else if(cash>500){
		  cash=cash-500;
		  five_hundred++;
		  cash_dispense::handle(cash);
	  }else if(cash<500){
		   cash_dispense::handle(cash);//call super handle so that next object on thhe chain get called
	  }
	  
	}
	
	int get_val(){
		return five_hundred;
	}
};



class cash_one_hundred:public cash_dispense{
    public:
	int one_hundred=0;
	void handle(int &cash){
	  if(cash==100){
		  cash=0;
		  one_hundred++;
	  }else if(cash>100){
		  cash=cash-100;
		  one_hundred++;
		  cash_dispense::handle(cash);
	  }else if(cash<100){
		   
	  }
	  
	}
	int get_val(){
		return one_hundred;
	}
	
};

int main(){
	
	int cash=29999;
	
	//base* b;
	cash_two_thousand root;//first object of the chain;
	cash_five_hundred five;
	cash_one_hundred one;
	
	root.add(&five);//add other objects to the chain
	root.add(&one);// add othher objects to the chain
	one.set_next(&root);//last element in chain points to first and make chain circular
	
	root.handle(cash);//call chhain of actions...
	
	cout<<"dispense amount :\n Two thousand "<<root.get_val()<<" \n five hundered "<<five.get_val()<<" \none hundered "<<one.get_val();;
	
}