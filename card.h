class Card {
    public:
        enum Suits {
            HEARTS = 3,
            DIAMONDS,
            CLUBS,
            SPADES
        };

        enum Ranks {
            TWO = 2,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            TEN,
            JACK,
            QUEEN,
            KING,
            ACE
        };

        Card(Ranks rank, Suits suit);
        virtual ~Card();
        int getRank();
        int getSuit();
        virtual int getFaceValue();
        void print();
    private:
        Ranks rank;
        Suits suit;
};