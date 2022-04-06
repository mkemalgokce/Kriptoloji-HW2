/*  Mustafa Kemal GOKCE
    18120205034
    Kriptoloji Odev2
    
*/
#include "Login.h"
#include "md5.h"

// Odevin ikincu kismi icin calistirilmasi gereken fonksiyon.
void Part2() {
    std::string my_text = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibu";
    std::cout << "Original MD5 :" << md5(my_text) << "\n" ;

    for(int i = 1; i<500; ++i) {
        if(i != 1) {
            my_text[i-1] = (char)((int)my_text[i-1]-1);
            
        }
        my_text[i] = (char)((int)my_text[i]+1);
        std::cout << i << ": " << md5(my_text) << "\n";
    }
    
    
}

// Odevin ilk kismi icin calistirilmasi gereken fonksiyon.
void Part1() {
    Login my_loginl;
}
int main(){
    
    Part2();
    //Part1();
    return 0;
}
