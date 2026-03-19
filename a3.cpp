 #include<iostream>
 using namespace std;

 class Cylinder{
    private:
         double radius;
         double height;
         static double PI;

   public:
       Cylinder(void):radius(5), height(10)
       {}

       Cylinder(double radius, double height):radius(radius),height(height)
       {}

       double getRadius(void){

        return this->radius;

       }
       
       void setRadius(double radius){

           this->radius= radius;

       }

       double getHeight(void){

        return this->height;

       }

       void setHeight(double height)
       {
            this->height=height;
       }

       double calculateVolume(void){

          double volume;
          volume = Cylinder :: PI *radius *radius *height;
          return volume;

       }
 };

 double Cylinder::PI =3.14;

 int main(){

          Cylinder c1;
          Cylinder c2(10.2,15.5);

         cout<<"volume 1 : " <<c1.calculateVolume()<<endl;
         cout<<"volume 2 : " <<c2.calculateVolume()<<endl;

          cout<<"radius : "<<c1.getRadius()<<endl;
          cout<<"height : "<<c1.getHeight()<<endl;
          c1.setRadius(6.2);
          c1.setHeight(11);

         cout<<"radius : "<<c2.getRadius()<<endl;
         cout<<"height : "<<c2.getHeight()<<endl;
         c2.setRadius(12);
         c2.setHeight(22.2);



 }
