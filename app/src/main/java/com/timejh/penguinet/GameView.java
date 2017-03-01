package com.timejh.penguinet;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import static com.timejh.penguinet.OpenGLLib.onChanged;
import static com.timejh.penguinet.OpenGLLib.onCreated;
import static com.timejh.penguinet.OpenGLLib.onTouch;
import static com.timejh.penguinet.OpenGLLib.step;

/**
 * Created by tokijh on 2017. 2. 28..
 */

public class GameView extends GLSurfaceView implements GLSurfaceView.Renderer {

    private static final int MAX_TOUCH_COUNT = 2;

    private SaveManager saveManager;

    public GameView(Context context) {
        super(context);
        setEGLConfigChooser(8, 8, 8, 0, 16, 0);
        setEGLContextClientVersion(2);
        setRenderer(this);
        requestFocus();
        setFocusableInTouchMode(true);

        saveManager = new SaveManager(context);
    }

    public void onDrawFrame(GL10 gl) {
        step();
    }

    public void onSurfaceChanged(GL10 gl, int w, int h) {
        onChanged(w, h);
    }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        onCreated(saveManager);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int pointer_count = event.getPointerCount(); // 현재 화면에 터치중인 수
        if (pointer_count > MAX_TOUCH_COUNT) pointer_count = MAX_TOUCH_COUNT; // 터치 수 제한

        // 터치 정보를 담을 장소
        // ID, EventType, x, y
        int touchEvent[][] = new int[pointer_count][4];

        int eventType = -1; // jni와 연결되는 이벤트 정의

        switch (event.getAction() & MotionEvent.ACTION_MASK) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN:
                eventType = 0; // 화면을 눌렀을때
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_POINTER_UP:
                eventType = 1; // 화면에서 땠을때
                break;
            case MotionEvent.ACTION_MOVE:
                eventType = 2; // 누른상태로 이동했을때때
                break;
        }
        for (int i = 0; i < pointer_count; i++) {
            touchEvent[i][0] = event.getPointerId(i); //터치한 순간부터 부여되는 포인트 고유번호.
            touchEvent[i][1] = eventType;
            touchEvent[i][2] = (int) (event.getX(i));
            touchEvent[i][3] = (int) (event.getY(i));
        }

        onTouch(touchEvent);
        return true;
    }
}
