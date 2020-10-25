package dao;

import pojo.Animal;

import java.util.ArrayList;
import java.util.List;

public interface animalCRUD {
     void addAnimal(Animal animal,ArrayList arrayList);
    void deleteAnimal(int index, ArrayList arrayList);
     void updateAnimal(int index,Animal animal, ArrayList arrayList);
     Animal selectAnimal(int index, ArrayList arrayList);
     List<Animal> getAnimalsByAgeIncreasing(ArrayList arrayList);
}
