import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.*;

/**
 * The main GUI window for the Media Player application.
 * Provides a user interface to interact with the media server.
 */
public class Window extends JFrame {
    private static final long serialVersionUID = 1L;
    private final JTextArea text;
    private final JButton button1, button2, button3;
    private final JMenuBar bar_menu;
    Client client;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;

    /**
     * Main entry point for the application.
     * @param argv Command line arguments (not used)
     */
    public static void main(String argv[]) {
        new Window();
    }

    /**
     * Constructs the main application window.
     * Initializes the GUI components and sets up event handlers.
     */
    public Window() {
        try {
            client = new Client(DEFAULT_HOST, DEFAULT_PORT);
        } catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+DEFAULT_HOST+":"+DEFAULT_PORT);
            System.exit(1);
        }
        System.out.println("Client connected to "+DEFAULT_HOST+":"+DEFAULT_PORT);

        // Initialize GUI components
        setTitle("MEDIA PLAYER");
        text = new JTextArea("message",1,30);
        JScrollPane scroll_text = new JScrollPane(text);
        add(scroll_text,BorderLayout.CENTER);

        // Create buttons
        button1 = new JButton("text1");
        button2 = new JButton("CLEAR");
        button3 = new JButton("EXIT");
        JButton button4 = new JButton("FIND_MEDIA");
        JButton button5 = new JButton("FIND_GROUPE");
        JButton button6 = new JButton("PLAY_MEDIA");
        JButton button7 = new JButton("DELETE_MEDIA");
        JButton button8 = new JButton("DELETE_COLLECTION");
        JButton button9 = new JButton("DISP_ALL");

        // Set up button panel
        JPanel panel = new JPanel();
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        panel.add(button4);
        panel.add(button5);
        panel.add(button6);
        panel.add(button7);
        panel.add(button8);
        panel.add(button9);

        // Set up menu bar and toolbar
        bar_menu = new JMenuBar();
        JMenu menu = new JMenu();
        menu.add(button1);
        menu.add(button2);
        menu.add(button4);
        menu.add(button5);
        menu.add(button6);
        menu.add(button7);
        menu.add(button8);
        menu.add(button9);
        JToolBar tool = new JToolBar();
        tool.add(button1);
        tool.add(button2);
        tool.add(button4);
        tool.add(button5);
        tool.add(button6);
        tool.add(button7);
        tool.add(button8);
        tool.add(button9);
        bar_menu.add(tool);
        bar_menu.add(menu); 
        add(panel,BorderLayout.SOUTH);

        // Add action listeners
        button1.addActionListener(new Click1());
        button2.addActionListener(new Click2());
        button3.addActionListener(new Click3());
        button4.addActionListener(new Click4());
        button5.addActionListener(new Click5());
        button6.addActionListener(new Click6());
        button7.addActionListener(new Click7());    
        button8.addActionListener(new Click8());
        button9.addActionListener(new Click9());

        // Finalize window setup
        setJMenuBar(bar_menu);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    /**
     * ActionListener for button1 ("text1" button).
     * Displays a greeting message in the text area.
     */
    class Click1 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            text.setText("Hello adventure");
        }
    }

    /**
     * ActionListener for button2 ("CLEAR" button).
     * Clears the text area.
     */
    class Click2 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            text.setText("");
        }
    }

    /**
     * ActionListener for button3 ("EXIT" button).
     * Terminates the application.
     */
    class Click3 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
    
    /**
     * ActionListener for button4 ("FIND_MEDIA" button).
     * Sends a FIND_MEDIA request to the server and displays the response.
     */
    class Click4 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = text.getText();
            String response = client.send("FIND_MEDIA " + name);
            String new_resp = response.replace('_', '\n');
            text.append("\n" + new_resp + "\n");
        }
    }

    /**
     * ActionListener for button5 ("FIND_GROUPE" button).
     * Sends a FIND_GROUPE request to the server and displays the response.
     */
    class Click5 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = text.getText();
            String response = client.send("FIND_GROUPE " + name);
            String new_resp = response.replace('_', '\n');
            text.append("\n" + new_resp + "\n");
        }
    }

    /**
     * ActionListener for button6 ("PLAY_MEDIA" button).
     * Sends a PLAY_MEDIA request to the server and displays the response.
     */
    class Click6 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = text.getText();
            String response = client.send("PLAY_MEDIA " + name);
            text.append("\n" + response + "\n");
        }
    }

    /**
     * ActionListener for button7 ("DELETE_MEDIA" button).
     * Sends a DELETE_MEDIA request to the server and displays the response.
     */
    class Click7 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = text.getText();
            String response = client.send("DELETE_MEDIA " + name);
            text.append("\n" + response + "\n");
        }
    }                   

    /**
     * ActionListener for button8 ("DELETE_COLLECTION" button).
     * Sends a DELETE_COLLECTION request to the server and displays the response.
     */
    class Click8 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = text.getText();
            String response = client.send("DELETE_COLLECTION " + name);
            text.append("\n" + response + "\n");
        }
    }

    /**
     * ActionListener for button9 ("DISP_ALL" button).
     * Sends a DISP_ALL request to the server and displays the response.
     */
    class Click9 implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = text.getText();
            String response = client.send("DISP_ALL " + name);
            String new_resp = response.replace('_', '\n');
            text.append("\n" + new_resp + "\n");
        }
    }
}