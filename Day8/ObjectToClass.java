package figure;
class Point {
    private int x;
    private int y;

    Point(int x,int y)
    {
        this.x=x;
        this.y=y;
    }

    int getX()
    {
        return this.x;
    }
    int getY()
    {
        return this.y;
    }



    void setX(int x)
    {
        this.x=x;
    }
    void setY(int y)
    {
        this.y=y;
    }

}

 abstract class Shape{
   private Point p;
   private double area;

   void setPoint(Point p)
   {
       this.p =p;
   }

    Point getPoint()
   {
     return p;
   }
    abstract double getArea();


}

class Rectangle extends Shape{

    private double height;
    private double width;
    Rectangle(Point p,double height,double width)
    {

        setPoint(p);

        this.height=height;
        this.width=width;

    }
    void setHeight(double height)
    {
        this.height=height;
    }
    void setWidth(double width)
    {
        this.width=width;
    }
    double getHeight()
    {
        return this.height;
    }
    double getWidth()
    {
        return this.width;
    }

    public double getArea()
    {
        return this.height*this.width;
    }

}

class Circle extends Shape{

    private double radius;

    Circle(Point centre,double radius)
    {
        setPoint(centre);
        this.radius=radius;
    }
    void setRadius(double radius)
    {
        this.radius=radius;
    }
    double getRadius()
    {
        return this.radius;
    }
   public double getArea()
    {
        return 3.1416*radius*radius;
    }
}

public class ObjectToClass {

    public static void main(String[] args) {
        Point p = new Point(11,22);
        System.out.println("Point: "+p.getX()+","+p.getY());
        Rectangle r = new Rectangle(p,30.0,50.0);
        System.out.println("R: "+r.getHeight()+","+r.getWidth());
        System.out.println("R-Area: "+r.getArea());
        r.setWidth(9.0);
        r.setHeight(7.0);
        Shape s = r ;
        System.out.println("S-point: "+s.getPoint().getX()+","+s.getPoint().getY());
        p.setX(5);
        p.setY(7);
        Circle c = new Circle(p,7.0);
        System.out.println("C: "+c.getRadius()+","+c.getArea());
        c.setRadius(5.0);
        s=c;
        System.out.println("S-Area: "+s.getArea());










    }




}
