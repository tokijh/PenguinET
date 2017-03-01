package com.timejh.penguinet;

import android.content.Context;
import android.content.SharedPreferences;

/**
 * 데이터를 저장하기 위한 클래스
 *
 * Created by tokijh on 2017. 3. 2..
 */

public class SaveManager {
    public static final String PACMAN_PREFERENCES = "com_zagayevskiy_pacman_store";

    private Context context;

    public SaveManager(Context _context) {
        context = _context;
    }

    public void saveBoolean(String key, boolean value) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putBoolean(key, value);
        editor.commit();
    }

    public boolean loadBoolean(String key, boolean defValue) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        return sp.getBoolean(key, defValue);
    }

    public void saveInt(String key, int value) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putInt(key, value);
        editor.commit();
    }

    public int loadInt(String key, int defValue) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        return sp.getInt(key, defValue);
    }

    public void saveFloat(String key, float value) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putFloat(key, value);
        editor.commit();
    }

    public float loadFloat(String key, float defValue) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        return sp.getFloat(key, defValue);
    }

    public void saveString(String key, String value) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putString(key, value);
        editor.commit();
    }

    public String loadString(String key, String defValue) {
        SharedPreferences sp = context.getSharedPreferences(PACMAN_PREFERENCES, Context.MODE_PRIVATE);
        return sp.getString(key, defValue);
    }
}
