//
//  main.cpp
//  taskB
//  Создать класс комната, имеющая площадь. Определить конструкторы и методы доступа. Создать класс однокомнатных квартир, содержащий комнату и кухню (ее площадь), этаж (комната содержится в классе однокомнатная квартира). Определить конструкторы, методы доступа. Определить производный класс однокомнатные квартиры с адресом (дополнительное поле - адрес). Определить конструкторы, деструктор и вывод в поток.
//  Created by Nikita Makeev on 10/16/20.
//
#include <iostream>
#include <string>
using namespace std;
class Room{
    int width{0},height{0};
    
    public:
    
    Room(){}
    ~Room(){}

    int getArea()const{return width*height;}
    
    int getWidth()const{return width;}

    int getHeight()const{return height;}

    void setWidth(int Width){width = Width;}

    void setHeight(int Height){height = Height;}

};
 
class oneRoomApartment{ // класс однокомнатной квартиры
    
    int floor,kitchen_area;
    
    public :
    
    void setFloor(int Floor){floor = Floor;}
    
    int getFloor()const{return floor;}
    
    int getKitchen_area()const{ return kitchen_area;}
    
    void setKitchen_area(int Kitchen_area){kitchen_area = Kitchen_area;}
    
    oneRoomApartment(){}
    ~oneRoomApartment(){}
    
  };
class oneRoomApartment_withAdress : public oneRoomApartment, public Room{
    char * adress;
    
    public:
    
    oneRoomApartment_withAdress(){}
    ~oneRoomApartment_withAdress(){}
    
    void setAdress(char * Adress){this->adress = Adress;}
    
     char *getAdress()const {return adress;}
  friend ostream& operator<<(ostream& os,const oneRoomApartment_withAdress& apartament)
  {
      return os << "floor: " << apartament.getFloor() << endl
      << "kitchen square: " << apartament.getKitchen_area() << endl
      << "livingRoom square: " << apartament.getArea() << endl
      << "adress: " << apartament.getAdress() << endl;
  }

};

int main(){
    oneRoomApartment_withAdress oneRoom;
    oneRoom.setFloor(5);
    oneRoom.setKitchen_area(24);
    oneRoom.setAdress("Becker street");
    oneRoom.setHeight(6);
    oneRoom.setWidth(8);
    cout << oneRoom;
  return 0;
}
