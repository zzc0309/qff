package tool;

import pojo.Animal;

import java.util.Scanner;

public class Tool {
    public static int display1(){
        System.out.println("1.增 2.删 3.改 4.查 5.按Age从小到大输出");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }
    public  static Animal creatAnimal(){
        Animal animal=new Animal();
        System.out.println("输入species");
        Scanner sc = new Scanner(System.in);
        animal.setSpecies(sc.nextLine());
        System.out.println("输入sex");
        animal.setSex(sc.nextLine());
        System.out.println("输入age");
        animal.setAge(sc.nextInt());
        return animal;
    }
    public static int display2(){
        System.out.println("输入想要删除或查找或修改的index");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }
}
