require 'colorize'
require 'byebug'

class EightQueens

  def initialize
    @grid = default_grid
    @queens = create_queens
  end

  def solve
    until @queens.all? { |queen, pos| pos.length == 2 }
      1.upto(8) do |i|

        curr_queen = "queen#{i}".to_sym

        if @queens[curr_queen] == []
          @queens[curr_queen] = find_space(curr_queen)
        else
          @queens[curr_queen] = change_space(curr_queen)
        end

      end

      display
    end

  end

  def find_space(queen)
    0.upto(7) do |x|
      0.upto(7) do |y|
        next if occupied?([x,y])
        next if threat?([x,y])
        return [x,y]
      end
    end
    return []
  end

  def change_space(queen)
    p_x, p_y = @queens[queen]
    start_x = (0..7).to_a
    start_y = (0..7).to_a
    start_x = start_x.drop(p_x + 1) + start_x.take(p_x + 1)
    start_y = start_y.drop(p_y + 1) + start_y.take(p_y + 1)

    @queens[queen] = []

    start_x.each do |x|
      start_y.each do |y|
        next if occupied?([x,y])
        next if threat?([x,y])
        return [x,y]
      end
    end
  end

  def occupied?(pos)
    @queens.values.include?(pos)
  end

  def threat?(pos)
    x, y = pos
    xes = @queens.values.map { |val| val[0] }
    yes = @queens.values.map { |val| val[1] }

    return true if xes.include?(x) || yes.include?(y)
    return true if diagonal_threat?(x, y)

    false

  end

  def diagonal_threat?(x, y)
    [[-1,-1],[-1,1],[1,-1],[1,1]].each do |dx, dy|
      i = 1
      until x + dx * i > 7 || x + dx * i < 0 || y + dy * i > 7 || y + dy * i < 0
        return true if @queens.values.include?([x + dx * i, y + dy * i] )
        i += 1
      end
    end
    false
  end


  def default_grid
    Array.new(8) {Array.new(8)}
  end

  def create_queens
    {
      :queen1 => [],
      :queen2 => [],
      :queen3 => [],
      :queen4 => [],
      :queen5 => [],
      :queen6 => [],
      :queen7 => [],
      :queen8 => []
    }
  end



  def display
    system("clear")
    render = ""
    @grid.each_with_index do |row, i1|
      row.each_with_index do |space, i2|
        if @queens.values.include?([i1,i2])
          this_space = " 👸 ".colorize(:background => :light_white) if (i1+i2).odd?
          this_space = " 👸 ".colorize(:background => :black) if (i1+i2).even?
        else
          this_space = "   ".colorize(:background => :light_white) if (i1+i2).odd?
          this_space = "   ".colorize(:background => :black) if (i1+i2).even?
        end
        # this_space.colorize(:background => :light_white) if (i1+i2).odd?
        # this_space.colorize(:background => :light_black) if (i1+i2).even?
        render += this_space
      end
      render += "\n"
    end

    puts render
  end

end


my_solver = EightQueens.new
my_solver.solve
