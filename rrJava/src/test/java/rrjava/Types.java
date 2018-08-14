package rrjava;

import org.junit.Test;

/**
 * 数据类型。
 */
public final class Types {

    /**
     * 原始数据类型。
     *
     * @see <a href="https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html">Primitive Data Types</a>
     */
    @Test
    public void primitiveTypes() {
        byte valInt8 = 0;
        short valInt16 = 0;
        int valInt32 = 0;
        long valInt64 = 0L;
        float valFloat32 = 0.0f;
        double valFloat64 = 0.0;
        char valChar16 = '\u0000';

        boolean valBool = false;

        Object valRef = null;
    }

    /**
     * 字面量。
     */
    @Test
    public void literals() {
        final byte BINARY = 0b01111111;
        final int DECIMAL = 2_147_483_647;
        final long HEXADECIMAL = 0x7F_FF_FF_FF_FF_FF_FF_FFL;
    }

}
