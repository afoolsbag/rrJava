package rrgroovy

import spock.lang.Specification

class UnitTests extends Specification {

    def "unitTest"() {
        setup:
        def lhv = 1 + 2
        def rhv = 3

        when:
        def result = lhv == rhv

        then:
        result
    }

}
