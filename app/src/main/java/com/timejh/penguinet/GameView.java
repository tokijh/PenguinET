package com.timejh.penguinet;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import static com.timejh.penguinet.OpenGLLib.nativeChanged;
import static com.timejh.penguinet.OpenGLLib.nativeCreated;
import static com.timejh.penguinet.OpenGLLib.nativeOnTouchEvent;
import static com.timejh.penguinet.OpenGLLib.nativeUpdateGame;

/**
 * Created by tokijh on 2017. 2. 28..
 */

public class GameView extends GLSurfaceView implements GLSurfaceView.Renderer {

    public GameView(Context context) {
        super(context);
        this.setRenderer(this);
        this.requestFocus();
        this.setRenderMode(RENDERMODE_WHEN_DIRTY);
        this.setFocusableInTouchMode(true);
    }

    public void onDrawFrame(GL10 gl) {
        nativeUpdateGame();
    }

    public void onSurfaceChanged(GL10 gl, int w, int h) {
        nativeChanged(w, h);
    }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        nativeCreated();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        nativeOnTouchEvent((int)event.getX(), (int)event.getY(), event.getAction());
        return true;
    }
}
