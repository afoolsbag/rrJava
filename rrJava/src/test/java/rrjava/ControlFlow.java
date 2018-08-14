package rrjava;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.util.Random;

import org.junit.Test;

/**
 * 控制流。
 */
public final class ControlFlow {

    /**
     * if 分支。
     *
     * @see <a href="https://docs.oracle.com/javase/tutorial/java/nutsandbolts/if.html">The if-then and if-then-else Statements</a>
     */
    @Test
    public void ifBranch() {
        Random random = new Random();
        if (random.nextBoolean()) {
            random.nextBoolean();
        } else if (random.nextBoolean()) {
            random.nextBoolean();
        } else {
            random.nextBoolean();
        }
    }

    /**
     * switch 分支。
     *
     * @see <a href="https://docs.oracle.com/javase/tutorial/java/nutsandbolts/switch.html">The switch Statement</a>
     */
    @Test
    public void switchBranch() {
        Random random = new Random();
        switch (random.nextInt(6)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                break;
            default:
                fail();
        }
    }

    /**
     * while 循环。
     *
     * @see <a href="https://docs.oracle.com/javase/tutorial/java/nutsandbolts/while.html">The while and do-while Statements</a>
     */
    @Test
    public void whileLoop() {
        Random random = new Random();

        int lucky = 0;
        while (random.nextBoolean()) {
            ++lucky;
        }
        assertTrue(0 <= lucky);

        int happy = 0;
        do {
            ++happy;
        } while (random.nextBoolean());
        assertTrue(1 <= happy);
    }

    /**
     * for 循环。
     *
     * @see <a href="https://docs.oracle.com/javase/tutorial/java/nutsandbolts/for.html">The for Statement</a>
     */
    @Test
    public void forLoop() {
        Random random = new Random();

        int lucky = 0;
        for (boolean cond = random.nextBoolean(); cond; cond = random.nextBoolean()) {
            ++lucky;
        }
        assertTrue(0 <= lucky);

        final int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int sum = 0;
        for (int number : numbers) {
            sum += number;
        }
        assertEquals(sum, 45);

    }

}
