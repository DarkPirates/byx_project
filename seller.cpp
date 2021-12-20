#include "seller.h"

int InitSe()
{
    //冗长的构造商品的代码。。。。
        Commodity_Fruit apple("21.12.1",1);                
        apple.SetNmae_("apple");
        apple.SetPrice_(3);

        Commodity_Fruit banana("21.12.1",1);
        banana.SetNmae_("Banana");
        banana.SetPrice_(2);
        
        Commodity_Fruit orange("22.1.1",1);
        orange.SetNmae_("orange");
        orange.SetPrice_(1);
        
        Commodity_Fruit durian("21.12.3",20);
        durian.SetNmae_("Durian");      
        durian.SetPrice_(100);  
        
        Commodity_Vegetables pepper(4);
        pepper.SetNmae_("pepper");
        pepper.SetPrice_(4);
        
        Commodity_Vegetables potato(5);
        potato.SetNmae_("potato");
        potato.SetPrice_(2);

        Commodity_Vegetables tomato(3);
        tomato.SetNmae_("tomato");
        tomato.SetPrice_(3);

        Commodity_Vegetables eggplant(6);
        eggplant.SetNmae_("eggplant");
        eggplant.SetPrice_(10);  

        Commodity_Furniture refrigerator(1,"nothing");
        refrigerator.SetNmae_("refrigerator");
        refrigerator.SetPrice_(5000);

        Commodity_Furniture washing_machine(2,"nothing");
        washing_machine.SetNmae_("washing_machine");
        washing_machine.SetPrice_(1000);

        Commodity_Furniture dishwasher(1,"nothing");
        dishwasher.SetNmae_("dishwasher");
        dishwasher.SetPrice_(1000);

        Commodity_Furniture bookshelf(2,"wood");
        bookshelf.SetNmae_("bookshelf");
        bookshelf.SetPrice_(300);

        Commodity_Clothes t_shirt("summer");
        t_shirt.SetNmae_("t_shirt");
        t_shirt.SetPrice_(30);

        Commodity_Clothes peaked_cap("all");
        peaked_cap.SetNmae_("peaked_cap");
        peaked_cap.SetPrice_(40);

        Commodity_Clothes sweater("all");
        sweater.SetNmae_("sweater");
        sweater.SetPrice_(50);

        Commodity_Clothes coat("=-=");
        coat.SetNmae_("coat");
        coat.SetPrice_(100);
}