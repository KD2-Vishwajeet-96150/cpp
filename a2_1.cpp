 #include<iostream>
 using namespace std;

 class Box{

    private:

    int length;
    int width;
    int height;


    public:

    Box (void){
        length=8;
        width=5;
        height=6;

    } 

    Box(int value){
        length=value;
        width=value;
        height=value;

    }

    Box( int length, int width, int height){
        this->length=length;
        this->width=width;
        this->height=height;

    }

    int calculateVolume(){
       
       return length*width*height;

    }

 };


int menuList(){
    int choice;
    cout<<"enter 0 to exit"<<endl;
    cout<<"enter 1 to Calculate Volume with default values"<<endl;
    cout<<"enter 2 to Calculate Volume with length,breadth and height with same value"<<endl;
    cout<<"enter 3 to Calculate Volume with different length,breadth and height values"<<endl;
    cin>>choice;

    return choice;
}


int main(){

        int choice;
        Box b1;
        Box b2(10);
        Box b3(8,6,7);

       while((choice=menuList())!=0){
        
           switch(choice){

            case 1:cout<<b1.calculateVolume()<<endl;
                   break;

           
            case 2:cout<<b2.calculateVolume()<<endl;
                   break;

            
           case 3:cout<<b3.calculateVolume()<<endl;
                   break;
            

           }

       }
        
}