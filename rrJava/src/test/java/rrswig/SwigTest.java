package rrswig;

import org.junit.Test;

import static org.junit.Assert.*;

public final class SwigTest {
    static {
        System.loadLibrary("rrlxswigjavad");
    }

    @Test
    public void getVersion() {
        var major = new int[1];
        var minor = new int[1];
        var patch = new int[1];
        var tweak = new int[1];
        Rrlx.getVersion(major, minor, patch, tweak);
        System.out.printf("getVersion: %d.%d.%d.%d\n", major[0], minor[0], patch[0], tweak[0]);
    }

    @Test
    public void ioBasic() {
        var handle = new CHandle();
        Rrlx.construct(handle.cast());

        final int data = 1337;
        Rrlx.setBasic(handle.value(), data);

        var value = new int[1];
        Rrlx.getBasic(handle.value(), value);

        assertEquals(data, value[0]);

        Rrlx.destruct(handle.value());
    }

    @Test
    public void ioArray() {
        var handle = new CHandle();
        Rrlx.construct(handle.cast());

        final int in_size = 4;
        var in = new CUInt8Array(in_size);
        in.setitem(0, (short) 1);
        in.setitem(1, (short) 3);
        in.setitem(2, (short) 3);
        in.setitem(3, (short) 7);
        Rrlx.setArray(handle.value(), in.cast(), in_size);

        var out_size = new long[1];
        out_size[0] = in_size;
        var out = new CUInt8Array((int) out_size[0]);
        Rrlx.getArray(handle.value(), out.cast(), out_size);

        assertEquals(in_size, out_size[0]);
        assertEquals(in.getitem(0), out.getitem(0));
        assertEquals(in.getitem(1), out.getitem(1));
        assertEquals(in.getitem(2), out.getitem(2));
        assertEquals(in.getitem(3), out.getitem(3));

        Rrlx.destruct(handle.value());
    }

    @Test
    public void ioString() {
        var handle = new CHandle();
        Rrlx.construct(handle.cast());

        final String data = "1337";
        Rrlx.setString(handle.value(), data);

        Rrlx.destruct(handle.value());
    }

    @Test
    public void ioCallback() {
        var handle = new CHandle();
        Rrlx.construct(handle.cast());

        Rrlx.destruct(handle.value());
    }

    @Test
    public void version() {
        var version = Rrlx.version();
        System.out.printf("getVersion: %d.%d.%d.%d\n", version.getMajor(), version.getMinor(), version.getPatch(), version.getTweak());
    }

    @Test
    public void clazzIoBasic() {
        var obj = new Clazz();

        final int data = 1337;
        obj.setBasic(data);
        assertEquals(data, obj.getBasic());
    }

    @Test
    public void clazzIoArray() {
        var obj = new Clazz();

        var in = new UInt8Vector();
        in.add((short) 1);
        in.add((short) 3);
        in.add((short) 3);
        in.add((short) 7);
        obj.setArray(in);

        final var out = obj.getArray();
        assertEquals(in.size(), out.size());
        assertEquals(in.get(0), out.get(0));
        assertEquals(in.get(1), out.get(1));
        assertEquals(in.get(2), out.get(2));
        assertEquals(in.get(3), out.get(3));
    }

    @Test
    public void clazzIoString() {
        var obj = new Clazz();

        final String data = "1337";
        obj.setString(data);
        assertEquals(data, obj.getString());
    }

    @Test
    public void clazzIoCallback() {
    }
}
