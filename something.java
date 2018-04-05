public class PolyFunctionPtrs {

    public static void main(String args[]) {

        PolyFunction[] arr = new PolyFunction[]{
            PolyFunction pf1 = new PolyFunction_1(),
            PolyFunction pf2 = new PolyFunction_2()

        }

        if (args.length == 0) {
            System.out.println("Must be called with a 0 or 1");
            System.exit(1);
        }
        int fNum = Integer.parseInt(args[0]);
        if (fNum == 1)
            pf1.pfunc();
        else
            pf2.pfunc();
    }

    private static interface PolyFunction {
        public void pfunc();
    }

    private static class PolyFunction_1 implements PolyFunction {
        public void pfunc() {
            System.out.println("in 1");
        }
    }

    private static class PolyFunction_2 implements PolyFunction {
        public void pfunc() {
            System.out.println("in 2");
        }
    }
}