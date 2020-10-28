//
//  main.cpp
//  taskB
//  Создать класс комната, имеющая площадь. Определить конструкторы и методы доступа. Создать класс однокомнатных квартир, содержащий комнату и кухню (ее площадь), этаж (комната содержится в классе однокомнатная квартира). Определить конструкторы, методы доступа. Определить производный класс однокомнатные квартиры с адресом (дополнительное поле - адрес). Определить конструкторы, деструктор и вывод в поток.
//  Created by Nikita Makeev on 10/16/20.
//
#include <iostream>
#include <string>
using namespace std;
    class Room{;
        public:
        Room(int area):m_nArea(area){}
        
        Room(const Room& room){
            m_nArea = room.GetArea();
        }
        
        ~Room(){}
        
        int GetArea()const{return m_nArea;}
        
    protected:
    int m_nArea;
};
    class LivingRoom : public Room {
        public:
        LivingRoom(int area):Room(area){}
        ~LivingRoom(){}
};
 
    class Kitchen : public Room {
        public:
            Kitchen(int area):Room(area){}
            ~Kitchen(){}
};
    class oneRoomApartment{
    
    public :
    
    oneRoomApartment(int floor, Kitchen kitchen_area, LivingRoom living_area):m_nFloor(floor){
        NewKitchen = new Kitchen(kitchen_area);
        NewLiving = new LivingRoom(living_area);
    };
        
    ~oneRoomApartment(){
        delete NewLiving;
        delete NewKitchen;
    }
        
        friend ostream& operator<<(ostream& os,const oneRoomApartment& apartament) //перегрузка оператора '<<'
        {
          return os << "floor: " << apartament.m_nFloor << endl
                    << "kitchen square: " << apartament.NewKitchen->GetArea() << endl
                    << "livingRoom square: " << apartament.NewLiving->GetArea() << endl;
        }
        int m_nFloor;
        Kitchen *NewKitchen;
        LivingRoom *NewLiving;
  };
class oneRoomApartment_withAdress : public oneRoomApartment{
    string m_nAdress;
    
    public:
    oneRoomApartment_withAdress(string adress, int floor, Kitchen kitchen_area,LivingRoom living_area ):oneRoomApartment(floor, kitchen_area, living_area),m_nAdress(adress){}
    
    ~oneRoomApartment_withAdress(){}
    
     string GetAdress()const {return m_nAdress;}
    
  friend ostream& operator<<(ostream& os,const oneRoomApartment_withAdress& apartament)
  {
      return os << "adress: " << apartament.GetAdress() << endl
                   << "livingRoom area: " << apartament.NewLiving->GetArea() << endl
                   << "kitchenRoom area: " << apartament.NewKitchen->GetArea() << endl
                   << "floor: " << apartament.m_nFloor << endl;
  }
};

int main(){
    oneRoomApartment oneRoom(5,(Kitchen)20, (LivingRoom)45);
    oneRoomApartment_withAdress oneRoom_w_adress("Beker street 221b :)",2, (Kitchen)25, (LivingRoom)50);
    cout << oneRoom;
    cout << oneRoom_w_adress;
  return 0;
}
