#include "model.hxx"
#include <catch.hxx>

// 1. Switching between screen
TEST_CASE("Switching between screen")
{
    Model model;

    // Start Screen Conditions
    CHECK_FALSE(model.check_active());
    CHECK_FALSE(model.board_placement());
    CHECK_FALSE(model.is_game_over());

    // Placement Screen Conditions
    model.start_placement(Model::Players::P1);

    CHECK_FALSE(model.check_active());
    CHECK(model.board_placement());
    CHECK_FALSE(model.is_game_over());

    model.shuffle_board();
    model.stop_placement();

    model.start_placement(Model::Players::P2);
    model.shuffle_board();
    model.stop_placement();

    // Game Screen Conditions
    model.start_game();

    CHECK(model.check_active());
    CHECK_FALSE(model.board_placement());
    CHECK_FALSE(model.is_game_over());

    // End Screen Conditions
    model.force_game_over(Model::Players::P1);

    CHECK_FALSE(model.check_active());
    CHECK_FALSE(model.board_placement());
    CHECK(model.is_game_over());
}

// 2. shuffling

TEST_CASE("board shuffling")
{
    Model model;

    model.start_placement(Model::Players::P1);
    model.shuffle_board();
    model.stop_placement();

    CHECK_FALSE(model.get_player1().get_board().is_empty());

    model.start_placement(Model::Players::P2);
    model.shuffle_board();
    model.stop_placement();

    CHECK_FALSE(model.get_player2().get_board().is_empty());
}

// 3. Check Winner
TEST_CASE("check winner") {
    Model model;

    model.start_placement(Model::Players::P1);
    model.shuffle_board();
    model.stop_placement();

    model.start_placement(Model::Players::P2);
    model.shuffle_board();
    model.stop_placement();

    model.start_game();
    model.force_game_over(Model::Players::P1);

    CHECK(model.get_winner() == "Player 1");
}

// 4. checking turns
TEST_CASE("check turns") {
    Model model;

    Board p1_board = model.get_player1().get_board();
    Board p2_board = model.get_player2().get_board();

    model.start_placement(Model::Players::P1);
    model.shuffle_board();
    model.stop_placement();

    model.start_placement(Model::Players::P2);
    model.shuffle_board();
    model.stop_placement();

    model.start_game();

    CHECK(model.get_turn() == Model::Players::P1);
    model.grid_clicked_board(p2_board.get_random_ship_pos());
    CHECK(model.get_turn() == Model::Players::P1);

    model.grid_clicked_board(p2_board.get_random_water_pos());
    CHECK(model.get_turn() == Model::Players::P2);
}

// 5. start button
TEST_CASE("start button") {
    Model model;

    model.start_placement(Model::Players::P1);
    model.shuffle_board();
    model.stop_placement();

    model.start_game();
    CHECK_FALSE(model.check_active());
    CHECK(model.get_player2().get_board().is_empty());

    model.start_placement(Model::Players::P2);
    model.shuffle_board();
    model.stop_placement();

    model.start_game();
    CHECK(model.check_active());
}

//Explanations

// Unit Test 1: Switching between Screens
// (starts at L5)
//
// in lines 10-13, we are checking that the initial screen conditions are what we expect them to be.
// We expect the game to be inactive when the players havent shuffled/placed ships.
// We also expect the game to not be over since no game has been started because the placement
//         is still also inactive.
//
// in line 15, we start the board placement for one of the players.
// this indicates that placement is active.
// we check that the game is inactive, which again it must be until BOTH players have placed ships.
// Then we check that the game is not considered over once a player places ships.
//
// in lines 21-22, we tell the model to shuffle the board of the current player/the player
// we told the model to start placement for.
// After we shuffle, the current player will have active ships.
// Then in line 22, we stop the placement in order to be able to move on to the next player.
//
// in lines 24-26, we start the placement phase for the second player
//         and shuffle its board in order for the p2 board to have ships.
// then we end the placement phase for the game by stopping the placement of the second player.
//
// after the placement phase, the game can start. We start the game in line 29.
// Since the placement phase is over and we are in the main phase, the game status should be active (L31),
//         board placement should be inactive (L32) and the game should be running (L33).
//
// we end this unit test by ending the game (L36) in order to check the ending screen/phase
//         of the game.
// at the end of the game, we expect the game to be inactive, the placement phase to remain inactive,
// and for the game to finally be over (L38-40).
//
//
// Unit Test 2: Board Shuffling
//         (L44)
//
// we start the game and place ships for one player.
// we check to make sure that the board shuffling function
// actually places ships on the players board by checking that the board
// is not empty (L52).
//
// a similar check is done for the second player in line 58 after shuffling the players
// board in lines 54-56.
//
// Unit Test 3: Check Winner
//         (L62)
//
// we begin the game as in the previous tests.
// we then force the game over and tell the game that winner is player1.
// we check that the game returns the correct winner in line 76.
//
//
// Unit Test 4: Check Turns
//         (L80)
//
// this unit test is focused on making sure that we are tracking the player turns
// correctly throughout the game.
//
// we expect that the turn at the beginning of the main phase of the game
//         should be player 1's turn.
//
// We check this by placing ships for both players in lines 86-92, then starting
// the game in L94.
//
// to see that the turn changes, we tell the model that the player
// clicked on a position that was in p2s board. this means that player 1 played
//         since each player is only able to click on the opposing players board.
//
// there are two conditions that we need to check to advance the turn:
//
// if the player hits an opponents ship, it is still their turn
//
// if the player does not hit an opponent ship, the turn changes.
//
// in lines 97-98, the player clicks on an opponents ship position and the turn does not change.
//
// in lines 100-101, the player misses the opponents ships and the turn changes to p2.
//
//
// Unit Test 5: Start Buttons
//         (L105)
//
// in this test, we focus on the functionality of the game in the beginning phases.
// this test primarily checks that the game is never set to active or starts until
// both players have placed their ships.
//
// when you play the game, if both players have not placed their ships,
// the start button doesnt do anything and the game never starts.
//
// we test this by placing ships for player 1 in lines L108-110 and then attempt
// to start the game in line 112.
// the game does not start and remains inactive (L113) due to P2's board being empty (L114)
//
// to test that the game only starts once both players have their ships,
// we shuffle and place ships for the second player than perform a check to see that
// the game is active once start_game is called (L120-121).
