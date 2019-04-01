package ex05.III;

/**
 * 点类
 * x,y座标
 * 计算点点距离 CalDistance
 * 计算点点成线，该线斜率
 *
 * @author WeiYuan
 * @version 0.1
 * @since JDK 11.0.2
 */
public class Dot {
    public double x, y;

    public Dot(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * 检测是否有点重复，不定参数。
     * 若有点重复则返回true，若无点重复则返回false
     *
     * @param dots
     * @return
     */
    public static boolean IfRepeat(Dot... dots) {
        for (int i = 0; i < dots.length; i++) {
            for (int j = i + 1; j < dots.length; j++) {
                if (CalDistance(dots[i], dots[j]) <= 1E-10)
                    return true;
            }
        }
        return false;
    }

    /**
     * 检测由AB和BC构成的直线是否垂直
     * 若垂直返回true，不垂直返回false
     *
     * @param dotA
     * @param dotC
     * @param dotB
     * @return
     */
    public static boolean IfVertical(Dot dotA, Dot dotB, Dot dotC) {
        if (CalSlope(dotA, dotB) == "notExist" || CalSlope(dotB, dotC) == "notExist") {
            if ((CalSlope(dotA, dotB) == "notExist" && Double.valueOf(CalSlope(dotB, dotC)) <= 1E-10) || (CalSlope(dotB, dotC) == "notExist" && Double.valueOf(CalSlope(dotA, dotB)) <= 1E-10)) {
                return true; //两线其中一线斜率不存在，特殊处理
            }
        } else if (Double.valueOf(CalSlope(dotA, dotB)) * Double.valueOf(CalSlope(dotB, dotC)) + 1 <= 1E-10) {
            return true;
        }
        return false;
    }

    public double CalDistance(Dot dot) {
        return Math.sqrt((dot.x - x) * (dot.x - x) + (dot.y - y) * (dot.y - y));
    } //该点到dot的距离

    public static double CalDistance(Dot dotA, Dot dotB) {
        return Math.sqrt((dotA.x - dotB.x) * (dotA.x - dotB.x) + (dotA.y - dotB.y) * (dotA.y - dotB.y));
    } //两点dotA dotB 之间距离

    public String CalSlope(Dot dot) {
        if (Math.abs(dot.x - this.x) - 0 <= 1E-10) {
            if (CalDistance(dot) <= 1E-10) {
                throw new RuntimeException("点重复");
            } else {
                return "notExist"; //斜率不存在
            }
        }
        return Double.toString((dot.y - y) / (dot.x - x));
    }

    public static String CalSlope(Dot dotA, Dot dotB) {
        if (Math.abs(dotA.x - dotB.x) <= 1E-10) {
            if (CalDistance(dotA, dotB) <= 1E-10) {
                throw new RuntimeException("点重复");
            } else {
                return "notExist"; //斜率不存在
            }
        }
        return Double.toString((dotA.y - dotB.y) / (dotA.x - dotB.x));
    }
}