class Ex{
   public:
    Ex();
        sf::Text nHS;
        sf::Font font;
        sf::Text scor;
        sf::Text hS;
        sf::Text hSN;
        sf::SoundBuffer Buffershoot;
        sf::Sound shoot;
        sf::Sprite fond;
        sf::SoundBuffer Bufferexplosion;
        sf::Sound explosion;
        sf::Sprite Sons;
        sf::Texture SonsT;
        sf::Texture SonsM;

        sf::Texture fireT;
        sf::Texture fondT;
        sf::Image ico;

        sf::Sprite close;
        sf::Texture closeT;

        int retour;

        sf::Sprite fire;
        bool touche=false;
        int posperso;
        int hperso;
        void fired();
        void loop();
        int height=10;
        int width=10;
        void sound();
        short b;
    private:

        bool move=false;
        bool sounds=true;


};
