package dao;

import pojo.Animal;

import java.sql.Connection;
import java.util.*;

public class animalCRUDImpl implements animalCRUD{
    public void addAnimal( Animal animal,ArrayList arrayList) {
        arrayList.add(animal);
    }

    public void deleteAnimal(int index, ArrayList arrayList) {
        arrayList.remove(index);
    }

    public void updateAnimal(int index,Animal animal, ArrayList arrayList) {
        arrayList.set(index,animal);
    }

    public List<Animal> getAnimalsByAgeIncreasing(ArrayList arrayList) {
        //list.sort(Comparator.comparing(User::getPrice))
        Collections.sort(arrayList, new Comparator<Animal>() {
            public int compare(Animal o1, Animal o2) {
                return o1.getAge().compareTo(o2.getAge());
            }
        });
        for (Object a : arrayList ){
            System. out .println(a.toString());
        }
        return arrayList;
    }

    public Animal selectAnimal(int index, ArrayList arrayList) {
        return (Animal)arrayList.get(index);
    }
}
