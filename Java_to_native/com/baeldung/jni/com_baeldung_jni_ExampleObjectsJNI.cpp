//
//  com_baeldung_jni_ExampleObjectsJNI.cpp
//  Java_to_native
//
//  Created by Артём Семёнов on 23.11.2019.
//  Copyright © 2019 Артём Семёнов. All rights reserved.
//

#include "com_baeldung_jni_ExampleObjectsJNI.h"
#include <iostream>

JNIEXPORT jobject JNICALL Java_com_baeldung_jni_ExampleObjectsJNI_createUser
  (JNIEnv *env, jobject thisObject, jstring name, jdouble balance) {
   
    // Создание объекта класса UserData
    jclass userDataClass = env->FindClass("com/baeldung/jni/UserData");
    jobject newUserData = env->AllocObject(userDataClass);

    // Получение полей UserData для установки
    jfieldID nameField = env->GetFieldID(userDataClass, "name", "Ljava/lang/String;");
    jfieldID balanceField = env->GetFieldID(userDataClass , "balance", "D");

    env->SetObjectField(newUserData, nameField, name);
    env->SetDoubleField(newUserData, balanceField, balance);

    return newUserData;
}

JNIEXPORT jstring JNICALL Java_com_baeldung_jni_ExampleObjectsJNI_printUserData
  (JNIEnv *env, jobject thisObject, jobject userData) {

    // Find the id of the Java method to be called
    jclass userDataClass = env->GetObjectClass(userData);
    jmethodID methodId = env->GetMethodID(userDataClass, "getUserInfo", "()Ljava/lang/String;");

    jstring result = (jstring)env->CallObjectMethod(userData, methodId);
    return result;
}
