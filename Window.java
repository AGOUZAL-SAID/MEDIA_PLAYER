import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.*;

public class Window extends JFrame{
    private static final long serialVersionUID = 1L;
    private final  JTextArea text;
    private final  JButton button1,button2,button3;
    JMenuBar bar_menu;
    public static void main(String argv[ ]) {
        new Window();
    }
    public Window(){
        setTitle("MEDIA PLAYER");
        text = new JTextArea("message",1,30);
        JScrollPane scroll_text = new JScrollPane(text);
        add(scroll_text,BorderLayout.CENTER);
        button1 = new JButton("text1");
        button2 = new JButton("text2");
        button3 = new JButton("EXIT");
        JPanel panel = new JPanel();
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        bar_menu = new JMenuBar();
        JMenu menu = new JMenu();
        menu.add(button1);
        menu.add(button2);
        JToolBar tool = new JToolBar();
        tool.add(button1);
        tool.add(button2);
        bar_menu.add(tool);
        bar_menu.add(menu); 
        add(panel,BorderLayout.SOUTH);
        button1.addActionListener(new Click1());
        button2.addActionListener(new Click2());
        button3.addActionListener(new Click3());
        setJMenuBar(bar_menu);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class Click1 implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e) {
            text.setText("Hello adventure");
            }
    }

    class Click2 implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            text.setText("ARE YOU READY !!!");
            }
    }
    class Click3 implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            System.exit(0);
            }
    }
    
    
}