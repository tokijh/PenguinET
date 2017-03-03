package com.timejh.penguinet;

import android.content.res.AssetManager;

/**
 * Created by tokijh on 2017. 2. 28..
 */

public class OpenGLLib {

    static {
        System.loadLibrary("gamesystem");
    }

    public static native void onCreated(SaveManager saveManager, AssetManager asset);

    public static native void onChanged(int w, int h);

    public static native void onTouch(int touchEvent[][]);

    public static native void step();

    public static native boolean stop();

    public static native void destroy();
}
