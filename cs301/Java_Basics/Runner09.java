interface Plugins {
    public void draw();

    public void save();
}

class TextEditorPlugin implements Plugins {
    public void draw() {
        System.out.println("Draw line!");
    }

    public void save() {
        System.out.println("Saved text!");
    }
}

class TextEditorPDF implements Plugins {
    public void draw() {
        System.out.println("Drawing Pdf!");
    }

    public void save() {
        System.out.println("Saving Pdf!");
    }
}

public class Runner09 {
    public static void main(String args[]) {
        System.out.println("Main function called...");
        Plugins tep = new TextEditorPlugin();
        tep.draw();
        tep.save();

        Plugins t = new TextEditorPDF();
        t.draw();
        t.save();
    }

}
