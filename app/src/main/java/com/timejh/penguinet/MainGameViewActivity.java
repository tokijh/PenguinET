package com.timejh.penguinet;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainGameViewActivity extends AppCompatActivity {

    GameView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        mView = new GameView(getApplication());
        setContentView(mView);
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
    }
}
