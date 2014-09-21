#!/usr/bin/env ruby

################################################################################
#                                                                              #
# File: greek2utf8.rb                                                          #
#                                   ++++++++++++++++++++++++++++++             #
# Copyright (C) 2012                + Author:  Foivos S. Zakkak  +             #
#                                   + Website: foivos.zakkak.net +             #
#                                   + Email:   foivos@zakkak.net +             #
#                                   ++++++++++++++++++++++++++++++             #
#                                                                              #
# This program is free software: you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by         #
# the Free Software Foundation, either version 3 of the License, or            #
# (at your option) any later version.                                          #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# GNU General Public License for more details.                                 #
#                                                                              #
# You should have received a copy of the GNU General Public License            #
# along with this program.  If not, see <http://www.gnu.org/licenses/>.        #
#                                                                              #
################################################################################

require 'optparse'
require 'iconv'

options = {}
option_parser = OptionParser.new do |opts|
  opts.banner = 'Greek encoding to utf-8 converter'
  opts.separator ''
  opts.separator %'Usage: #{opts.program_name} FILE [OPTIONS]'
  opts.separator ''
  opts.separator 'Options'

  opts.on('-o', '--outputfile FILE', 'File to write the output') do |v|
    options[:output] = v
  end


  avail_encs = %w[windows-1253 iso-8859-7]
  options[:enc] = 'windows-1253'
  opts.on('-e', '--encoding TYPE', avail_encs, 'Encoding of input file',
                  "(#{avail_encs.join(',')})",
                  'defaults to windows-1253') do |e|
    options[:enc] = e
  end

  opts.separator ''
  opts.separator 'Common options:'

  opts.on_tail('-h','--help','Show this message') do
    puts option_parser
    exit 0;
  end
end

begin
  option_parser.parse!(ARGV)
rescue OptionParser::InvalidOption, OptionParser::MissingArgument
  puts option_parser
  exit 1;
end

if ARGV.length == 0
  puts option_parser
  exit 1;
end

data = File.read(ARGV[0])

conv = Iconv.new('utf-8', options[:enc])
result = conv.iconv(data)

$stderr.puts %'The input file encoding is defined as #{options[:enc]}'

if options[:output]
  puts %'Output file = #{options[:output]}'
  File.open(options[:output], 'w') do |fp|
    fp.puts(result)
  end
else
  puts result
end
