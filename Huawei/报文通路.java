

// 报文通路判断

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Route {
        int start;
        int end;
        boolean startToEnd;
        boolean endToStart;

        public boolean equals(Route obj) {
            return (obj.start == this.start && obj.end == this.end) || (obj.start == this.end && obj.end == this.start);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int line = Integer.parseInt(sc.nextLine());
        List<Route> routes = new ArrayList<>();
        for (int i = 0; i < line; i++) {
            Route route = new Route();
            String str = sc.nextLine();
            route.start = Integer.parseInt(str.split(" ")[0]);
            route.end = Integer.parseInt(str.split(" ")[1]);
            Route objRoute = findRoute(routes, route);
            if (objRoute == null) {
                route.startToEnd = true;
                routes.add(route);
            } else {
//                System.out.println(objRoute.end + "-" + route.start);
                if (objRoute.end == route.start) {
                    objRoute.endToStart = true;
                }
            }
        }
        for (Route r : routes) {
            if (r.startToEnd == false || r.endToStart == false) {
                System.out.println("FALSE");
                System.exit(0);
            }
        }
        System.out.println("TRUE");
    }

    public static Route findRoute(List<Route> routes, Route route) {
        for (Route r : routes) {
            if (r.equals(route)) {
                return r;
            }
        }
        return null;
    }
}

