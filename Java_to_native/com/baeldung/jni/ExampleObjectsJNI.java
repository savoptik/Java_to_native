package com.baeldung.jni;

public class ExampleObjectsJNI {

    static {
        System.loadLibrary("native");
    }

    public native UserData createUser(String name, double balance);
    public native String printUserData(UserData user);
}
