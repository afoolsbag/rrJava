package rrgroovy

import static org.junit.Assert.assertEquals;

import org.junit.Test

/**
 * 控制流。
 */
class ControlFlow {

    /**
     * for in 循环。
     */
    @Test
    void forLoop() {
        def sum = 0
        for (num in 1..9) {
            sum += num
        }
        assertEquals(sum, 45)
    }

}
