package rrjni;

public class JNI {
    static {
        System.loadLibrary("rrjni");
    }

    public native void ioVoid();

    public native byte ioByte(byte in);

    public native byte[] ioByteArray(byte[] in);

    public native short ioShort(short in);

    public native short[] ioShortArray(short[] in);

    public native int ioInt(int in);

    public native int[] ioIntArray(int[] in);

    public native long ioLong(long in);

    public native long[] ioLongArray(long[] in);

    public native float ioFloat(float in);

    public native float[] ioFloatArray(float[] in);

    public native double ioDouble(double in);

    public native double[] ioDoubleArray(double[] in);

    public native char ioChar(char in);

    public native char[] ioCharArray(char[] in);

    public native boolean ioBoolean(boolean in);

    public native boolean[] ioBooleanArray(boolean[] in);

    public native String ioString(String in);

    public native String[] ioStringArray(String[] in);
}
