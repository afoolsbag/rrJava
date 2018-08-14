package rrscala

import org.junit.runner.RunWith
import org.scalatest.FunSuite
import org.scalatest.junit.JUnitRunner

/** 数据类型。
  *
  * @see [[https://scala-lang.org/files/archive/spec/2.12/04-basic-declarations-and-definitions.html#variable-declarations-and-definitions Variable Declarations and Definitions]]
  */
@RunWith(classOf[JUnitRunner])
class Types extends FunSuite {

  test("types") {
    val objInt8: Byte = 0
    val objInt16: Short = 0
    val objInt32: Int = 0
    val objInt64: Long = 0L
    val objFloat32: Float = 0.0f
    val objFloat64: Double = 0.0d
    val objChar16: Char = 0

    val objBool: Boolean = false

    val objUnit: Unit = ()

    val objOther = null
  }

}
