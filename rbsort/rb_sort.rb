## This Array sort uses only linear time complexity,
## yet it requires an unsorted array of unique positive integers

class Array

  def rb_sort

    my_max = self.max + 1

    my_buckets = Array.new( my_max )

    self.each do |val|
      bucket = val % my_max
      my_buckets[bucket] = val
    end

    my_buckets.compact
  end

end

## Tests:

r = 1000000000
a1 = (0..r).to_a.shuffle

system('clear')
puts "Quantity to sort = #{r}"

beginning = Time.now

b = a1.sort

puts "Array sort. Time elapsed: #{Time.now - beginning} seconds."

beginning = Time.now

c = a1.rb_sort

puts "RB sort. Time elapsed: #{Time.now - beginning} seconds."

puts "Sorts return same value as each other: #{b == c}"
puts "Sorts return different value than original: #{a1 != b && a1 != c}"
gets
