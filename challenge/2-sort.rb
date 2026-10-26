#!/usr/bin/env ruby

result = ARGV.select { |arg| arg =~ /\A-?\d+\z/ }.map(&:to_i).sort

result.each do |n|
  puts n
end

