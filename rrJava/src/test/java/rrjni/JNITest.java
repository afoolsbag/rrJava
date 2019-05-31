package rrjni;

import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.*;

public final class JNITest {
    @Test
    public void ioVoid() {
        new JNI().ioVoid();
    }

    @Test
    public void ioByte() {
        final byte data = 8;
        assertEquals(data, new JNI().ioByte(data));
    }

    @Test
    public void ioByteArray() {
        final byte[] data = {1, 3, 3, 7};
        assertArrayEquals(data, new JNI().ioByteArray(data));
    }

    @Test
    public void ioShort() {
        final short data = 16;
        assertEquals(data, new JNI().ioShort(data));
    }

    @Test
    public void ioShortArray() {
        final short[] data = {1, 3, 3, 7};
        assertArrayEquals(data, new JNI().ioShortArray(data));
    }

    @Test
    public void ioInt() {
        final int data = 32;
        assertEquals(data, new JNI().ioInt(data));
    }

    @Test
    public void ioIntArray() {
        final int[] data = {1, 3, 3, 7};
        assertArrayEquals(data, new JNI().ioIntArray(data));
    }

    @Test
    public void ioLong() {
        final long data = 64L;
        assertEquals(data, new JNI().ioLong(data));
    }

    @Test
    public void ioLongArray() {
        final long[] data = {1L, 3L, 3L, 7L};
        assertArrayEquals(data, new JNI().ioLongArray(data));
    }

    @Test
    public void ioFloat() {
        final float data = 32f;
        assertEquals(data, new JNI().ioFloat(data), 0);
    }

    @Test
    public void ioFloatArray() {
        final float[] data = {1f, 3f, 3f, 7f};
        assertArrayEquals(data, new JNI().ioFloatArray(data), 0);
    }

    @Test
    public void ioDouble() {
        final double data = 64;
        assertEquals(data, new JNI().ioDouble(data), 0);
    }

    @Test
    public void ioDoubleArray() {
        final double[] data = {1, 3, 3, 7};
        assertArrayEquals(data, new JNI().ioDoubleArray(data), 0);
    }

    @Test
    public void ioChar() {
        final char data = '\0';
        assertEquals(data, new JNI().ioChar(data));
    }

    @Test
    public void ioCharArray() {
        final char[] data = {'\1', '\3', '\3', '\7'};
        assertArrayEquals(data, new JNI().ioCharArray(data));
    }

    @Test
    public void ioBoolean() {
        assertTrue(new JNI().ioBoolean(true));
    }

    @Test
    public void ioBooleanArray() {
        final boolean[] data = {true, false, false, true};
        assertArrayEquals(data, new JNI().ioBooleanArray(data));
    }

    @Test
    public void ioString() {
        final String data = "Quick brown fox jumps over the lazy dog.";
        assertEquals(data, new JNI().ioString(data));
    }

    @Test
    public void ioStringArray() {
        final String[] data = {"smt", "zl", "jt"};
        assertArrayEquals(data, new JNI().ioStringArray(data));
    }
}
