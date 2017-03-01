package com.timejh.penguinet;

/**
 * Created by tokijh on 2017. 2. 28..
 */

public class OpenGLLib {

    static {
        System.loadLibrary("gamesystem");
    }

    public static native void nativeCreated();

    public static native void nativeChanged(int w, int h);

    public static native void nativeUpdated();

    public static native void nativeOnTouchEvent(int touchEvent[][]);

}
