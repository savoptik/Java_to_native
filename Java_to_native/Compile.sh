#!/bin/sh

#  Compile.sh
#  nativ_to_java
#
#  Created by Артём Семёнов on 22.11.2019.
#  Copyright © 2019 Артём Семёнов. All rights reserved.

cd ./Java_to_native/com/baeldung/jni &&
javac -h . ExampleObjectsJNI.java UserData.java Main.java &&
g++ -c -fPIC -I /Library/Java/JavaVirtualMachines/jdk-11.0.5.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk-11.0.5.jdk/Contents/Home/include/darwin com_baeldung_jni_ExampleObjectsJNI.cpp -o com_baeldung_jni_ExampleObjectsJNI.o &&
g++ -dynamiclib -o libnative.dylib com_baeldung_jni_ExampleObjectsJNI.o -lc &&
cd .. && cd .. && cd .. &&
 java -cp . -Djava.library.path=./com/baeldung/jni com.baeldung.jni.Main
