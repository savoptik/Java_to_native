package com.baeldung.jni;


public class Main {
    public static void main(String[] args) {
        ExampleObjectsJNI eoj = new ExampleObjectsJNI();
        UserData ud = eoj.createUser("artem", 27);
        System.out.println(eoj.printUserData(ud));
    }
}
