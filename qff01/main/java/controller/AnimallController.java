package controller;

import dao.animalCRUDImpl;
import tool.Tool;

import java.util.ArrayList;

public class AnimallController {
    public static void main(String[] args) {
        ArrayList arrayList = new ArrayList();
        animalCRUDImpl animalCRUD = new animalCRUDImpl();
        while (true) {
            int a = Tool.display1();
            if (a == 1) {
                animalCRUD.addAnimal(Tool.creatAnimal(), arrayList);
            } else if (a == 2) {
                animalCRUD.deleteAnimal(Tool.display2(), arrayList);
            } else if (a == 3) {
                animalCRUD.updateAnimal(Tool.display2(), Tool.creatAnimal(), arrayList);
            } else if (a == 4) {
                System.out.println(animalCRUD.selectAnimal(Tool.display2(), arrayList));
            }else if(a==5){
                animalCRUD.getAnimalsByAgeIncreasing(arrayList);
            }
        }
    }
}
