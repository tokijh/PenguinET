package com.timejh.penguinet;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;

public class MainGameViewActivity extends AppCompatActivity {

    GameView mView;

    @Override
    protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        mView = new GameView(getApplication());
        setContentView(mView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        OpenGLLib.stop();
        mView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        OpenGLLib.step();
        mView.onResume();
    }

    @Override
    protected void onStop() {
        super.onStop();
        OpenGLLib.destroy();
        finish();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK) {
            if(OpenGLLib.stop()){
                finish();
            }
            return true;
        }
        return super.onKeyDown(keyCode, event);
    }
}
